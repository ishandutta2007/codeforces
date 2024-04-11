#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
const int MOD = (int)1e9+7;
const int MAXN = 102;
struct node{
    int a[MAXN][MAXN];
    int n,m;
    node(int N,int M){
        memset(a,0,sizeof(a));
        n=N;m=M;
    }
};

int add(int x,int y)
{
    x+=y;
    if(x>=MOD)x-=MOD;
    return x;
}

node operator * (const node&a,const node&b)
{
    node c(a.n,b.m);
    for(int i=1;i<=a.n;i++)
    for(int j=1;j<=b.m;j++){
        int res=0;
        for(int k=1;k<=a.m;k++)
            res = add(res , (ll)a.a[i][k]*b.a[k][j]%MOD);
        c.a[i][j]=res;
    }
    return c;
}
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    node a(1,101),b(101,101);
    a.a[1][1]=a.a[1][101]=1;
    b.a[101][1]=b.a[101][101]=1;
    for(int i=2;i<=100;i++)
        b.a[i-1][i]=1;
    for(int i=0;i<n;i++){
        int v;
        scanf("%d",&v);
        b.a[v][1]++;
    }
    while(x){
        if(x&1)a=a*b;
        b=b*b;
        x>>=1;
    }
    printf("%d\n",a.a[1][1]);
    return 0;
}