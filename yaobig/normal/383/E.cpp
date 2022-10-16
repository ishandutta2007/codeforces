#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn (1<<24)
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef double db;

int ps[maxn];
char s[10];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n)
    {
        scanf("%s",s);
        int x=1<<(s[0]-'a'),y=1<<(s[1]-'a'),z=1<<(s[2]-'a');
        ps[x]++; ps[y]++; ps[z]++;
        ps[x|y]--; ps[y|z]--; ps[z|x]--;
        ps[x|y|z]++;
    }
    int N=1<<24;
    rep(i,0,23) rep(s,0,N-1) if(s&(1<<i)) ps[s]+=ps[s^(1<<i)];
    int ans=0;
    rep(s,0,N-1) ans^=ps[s]*ps[s];
    printf("%d\n",ans);
    return 0;
}