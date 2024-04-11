#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n,cc[50][50];
char s[1005];
bool was[50];

int main() {
    scanf("%d",&n);
    rep(i,0,n) {
        scanf("%s",s);
        rep(j,0,26) was[j]=false;
        rep(j,0,strlen(s)) was[s[j]-'a']=true;
        VI v;
        rep(j,0,26) if (was[j]) v.pb(j);
        if (SZ(v)==1) cc[v[0]][v[0]]+=strlen(s);
        if (SZ(v)==2) cc[v[0]][v[1]]+=strlen(s);
    }
    int ans=0;
    rep(i,0,26) rep(j,0,26) if (i!=j) ans=max(ans,cc[i][i]+cc[j][j]+cc[i][j]);
    printf("%d",ans);
}