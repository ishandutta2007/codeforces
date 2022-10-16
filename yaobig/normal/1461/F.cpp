#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];
bool can[255];

struct node
{
    int l,r,sum;
};

vector<char> solve(vi a)
{
    int n=a.size()-1;
    vector<char> ans(n+2,'*');
    ll prod=1;
    rep(i,1,n) 
    {
        prod*=a[i];
        if(prod>n*2) 
        {
            rep(j,1,n) if(a[j]==1) ans[j]='+'; else break;
            per(j,1,n) if(a[j]==1) ans[j-1]='+'; else break;
            return ans;
        }
    }
    vi pp(n+1);
    pp[0]=1; rep(i,1,n) pp[i]=pp[i-1]*a[i];
    vector<node> A(1);
    int be=1;
    rep(i,1,n) if(a[i]!=1)
    {
        assert(a[i]>1);
        if(i>be)
        {
            A.pb({be,i-1,i-be});
        }
        A.pb({i,i,-inf});
        be=i+1;
    }
    if(be<=n) A.pb({be,n,n-be+1});
    int N=A.size()-1;
    vi dp(N+1,0),pre(N+1,0);
    rep(i,1,N)
    {
        dp[i]=pp[A[i].r];
        rep(j,1,i) 
        {
            int prod=j<i?pp[A[i].r]/pp[A[j].r]:0;
            if(A[j].sum>0 && dp[i]<dp[j-1]+A[j].sum+prod) 
            {
                dp[i]=dp[j-1]+A[j].sum+prod;
                pre[i]=j;
            }
        }
    }
    int now=N;
    //printf("fuck n = %d\n",n);
    //rep(i,1,n-1) printf("?? %d: %c\n",i,ans[i]);
    while(now)
    {
        now=pre[now];
        if(now==0) break;
        rep(i,A[now].l-1,A[now].r) ans[i]='+';
        now--;
    }
    return ans;
}

void solve2(int n,char op)
{
    rep(i,1,n) printf("%d%c",a[i],i==n?'\n':op);
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    char op[10]; scanf("%s",op+1); 
    int opn=strlen(op+1);
    rep(i,1,opn) can[(int)op[i]]=1;
    if(can['+'] && can['*'])
    {
        vector<char> ans(n+2);
        int be=1;
        rep(i,1,n+1) if(a[i]==0)
        {
            if(i>be) 
            {
                vi ta(1,0);
                rep(j,be,i-1) ta.pb(a[j]);
                vector<char> tmp=solve(ta);
                rep(j,be,i-1) ans[j]=tmp[j-be+1];
            }
            ans[i-1]='+';
            ans[i]='+';
            be=i+1;
        }
        //rep(i,1,n-1) printf("? %d: %c\n",i,ans[i]);
        rep(i,1,n) printf("%d%c",a[i],i==n?'\n':ans[i]);
    }
    else if(can['*']) 
    {
        vector<char> ans(n+2,'*');
        if(can['-']) 
        {
            rep(i,1,n) if(a[i]==0) ans[i-1]='-';
        }
        rep(i,1,n) printf("%d%c",a[i],i==n?'\n':ans[i]);
    }
    else if(can['+']) solve2(n,'+');
    else solve2(n,'-');
    return 0;
}