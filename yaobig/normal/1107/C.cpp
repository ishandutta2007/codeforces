#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int n,k;
char s[maxn+5];
int a[maxn+5];
int v[maxn+5],tot;

ll cal()
{
    ll res=0;
    if(tot>k) nth_element(v+1,v+k,v+tot+1,greater<int>());
    rep(i,1,min(tot,k)) res+=v[i];
    return res;
}


int main()
{
    scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d",&a[i]);
    scanf("%s",s+1);
    ll ans=0;
    rep(i,1,n)
    {
        if(s[i]!=s[i-1])
        {
            ans+=cal();
            tot=0;
        }
        v[++tot]=a[i];
    }
    ans+=cal();
    printf("%I64d\n",ans);
    return 0;
}