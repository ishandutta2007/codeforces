#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define maxL 300000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

typedef unsigned long long hashv;

hashv base=131;
hashv pw[maxL+5],hx[maxL+5],obj;

string s[maxn+5];
int len,ans;
vi e[maxn+5];

void dfs(int now,int L)
{
    if(now>1)
    {
        int l=s[now].length();
        rep(i,0,l-1)
        {
            L++;
            hx[L]=hx[L-1]*base+s[now][i];
            if(L>=len && hx[L]-hx[L-len]*pw[len]==obj) ans++;
        }
    }
    for(auto v: e[now]) dfs(v,L);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    pw[0]=1;
    rep(i,1,maxL) pw[i]=pw[i-1]*base;

    int n; cin>>n;
    rep(i,2,n)
    {
        int x; cin>>x>>s[i];
        e[x].pb(i);
    }
    string str; cin>>str;
    len=str.length();
    rep(i,0,len-1) obj=obj*base+str[i];
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}