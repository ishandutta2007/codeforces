#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5][maxn+5];
int b[maxn+5],id[maxn+5];
int n,m;
int mn;

bool cmp(int x,int y) {return b[x]>b[y];}

void check(int x,int y,vi &res)
{
    rep(i,1,m) b[i]=a[i][x]-a[i][y];
    rep(i,1,m) id[i]=i;
    sort(id+1,id+m+1,cmp);
    ll sum=0;
    rep(i,1,m)
    {
        sum+=b[id[i]];
        if(sum<0)
        {
            if(m-i+1<mn)
            {
                mn=m-i+1;
                res.clear();
                rep(j,i,m) res.pb(id[j]);
            }
            return;
        }
    }
    mn=0;
    res.clear();
}

int main()
{
	scanf("%d%d",&n,&m);
    rep(i,1,m) rep(j,1,n) scanf("%d",&a[i][j]);
    mn=inf;
    vi res;
    rep(i,1,n-1) check(i,n,res);
    printf("%d\n",mn);
    assert(mn==res.size());
    if(mn) rep(i,0,mn-1) printf("%d%c",res[i]," \n"[i==mn-1]);
    else puts("");
	return 0;
}