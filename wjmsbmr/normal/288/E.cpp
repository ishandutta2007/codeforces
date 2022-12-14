#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define P 1000000007
#define N 100010
char s[N],t[N];
int n;int f0[N][4],f1[N][4],f2[N][4];bool g[N][4];
int p10[N],p4[N],p7[N];
void ff(int x,int y)
{
    if(g[x][y])return;
    g[x][y]=1;
    int le=(y&1)?s[x]-'0':4,ri=(y&2)?t[x]-'0':7;
    if(x==0)
    {
        if(le!=4||ri!=7)return;
        f0[x][y]=1,
        f1[x][y]=4+7,
        f2[x][y]=4*7;
        return;
    }
    if(le<=4&&4<=ri)
    {
        int y2=0;
        if(4==le&&(y&1))y2^=1;
        if(4==ri&&(y&2))y2^=2;
        ff(x-1,y2);
        int k=(ll)p10[x]*4%P;
        f0[x][y]=((ll)f0[x][y]+f0[x-1][y2])%P;
        f1[x][y]=((ll)f1[x][y]+(ll)k*2%P*f0[x-1][y2]%P+f1[x-1][y2])%P;
        f2[x][y]=((ll)f2[x][y]+(ll)k*k%P*f0[x-1][y2]%P+(ll)k*f1[x-1][y2]%P+f2[x-1][y2])%P;
    }
    if(le<=7&&7<=ri)
    {
        int y2=0;
        if(7==le&&(y&1))y2^=1;
        if(7==ri&&(y&2))y2^=2;
        ff(x-1,y2);
        int k=(ll)p10[x]*7%P;
        f0[x][y]=((ll)f0[x][y]+f0[x-1][y2])%P;
        f1[x][y]=((ll)f1[x][y]+(ll)k*2%P*f0[x-1][y2]%P+f1[x-1][y2])%P;
        f2[x][y]=((ll)f2[x][y]+(ll)k*k%P*f0[x-1][y2]%P+(ll)k*f1[x-1][y2]%P+f2[x-1][y2])%P;
    }
    if(le==4&&ri==7)
    {
        int le=((ll)p10[x]*4+p7[x])%P,ri=((ll)p10[x]*7+p4[x])%P;
        f0[x][y]=((ll)f0[x][y]+1)%P;
        f1[x][y]=((ll)f1[x][y]+le+ri)%P;
        f2[x][y]=((ll)f2[x][y]+(ll)le*ri)%P;
    }
}
int main()
{
    p10[0]=1,p4[0]=0,p7[0]=0;
    for(int i=1;i<N;i++)
        p10[i]=(ll)p10[i-1]*10%P,
        p4[i]=((ll)p4[i-1]*10+4)%P,
        p7[i]=((ll)p7[i-1]*10+7)%P;
    scanf("%s%s",s,t);n=strlen(s);
    reverse(s,s+n),reverse(t,t+n);
    ff(n-1,3);
    printf("%d\n",f2[n-1][3]);
    return 0;
}