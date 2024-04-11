#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 500000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

typedef unsigned long long hashv;
const hashv base=131;

hashv hx[maxn+5],pw[maxn+5];
int a[maxn+5];
int cnt[maxn+5],freq[maxn+5];

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    pw[0]=1;
    rep(i,1,maxn) pw[i]=pw[i-1]*base;

    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) 
    {
        int x=a[i];
        int old=freq[x];
        freq[x]=(freq[x]+1)%3;
        hx[i]=hx[i-1]-old*pw[x]+freq[x]*pw[x];
    }

    unordered_map<hashv,int> hxcnt;
    ll ans=0;
    int front=1;
    hxcnt[hx[0]]++;
    rep(i,1,n)
    {
        int x=a[i];
        cnt[x]++;
        hxcnt[hx[i]]++;
        while(cnt[x]>3)
        {
            cnt[a[front]]--;
            hxcnt[hx[front-1]]--;
            front++;
        }
        ans+=hxcnt[hx[i]]-1;
    }
    printf("%lld\n",ans);
    return 0;
}