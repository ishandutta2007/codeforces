#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100000
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int pw(int x,int k)
{
    int res=1;
    while(k)
    {
        if(k&1) res*=x;
        x*=x;
        k>>=1;
    }
    return res;
}
int n,k,d;
char RESP[10];
bool checkleaf(int a)
{
    int c;
    rep(i,1,n)
    {
        if(i==a) continue;
        if(c==0) c=i;
        else
        {
            printf("? %d %d %d\n",i,a,c);
            fflush(stdout);
            scanf("%s",RESP);
            if(RESP[0]=='Y') return 0;
        }
    }
    return 1;
}
int findleaf()
{
    while(1)
    {
        int x=rand()%n+1;
        if(checkleaf(x)) return x;
    }
}
vi V;
bool hasroot(int a,int c)
{
    V.clear();
    rep(i,1,n)
    {
        printf("? %d %d %d\n",a,i,c);
        fflush(stdout);
        scanf("%s",RESP);
        if(RESP[0]=='Y') V.pb(i);
    }
    if((int)V.size()==2*d-1) return 1;
    return 0;
}
int main()
{
    srand(time(NULL));
    scanf("%d%d",&n,&k);
    for(d=2;pw(k,d)-1!=n*(k-1);d++);

    int l1=findleaf(),l2;
    while(1)
    {
        l2=findleaf();
        if(hasroot(l1,l2)) break;
    }
    int ans=0;
    for(auto r: V)
    {
        int cnt=0;
        for(auto v: V)
        {
            printf("? %d %d %d\n",l1,v,r);
            fflush(stdout);
            scanf("%s",RESP);
            if(RESP[0]=='Y') cnt++;
        }
        if(cnt==d)
        {
            ans=r;
            break;
        }
    }
    printf("! %d\n",ans);
    fflush(stdout);
    return 0;
}