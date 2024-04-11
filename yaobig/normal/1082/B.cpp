#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

char s[maxn+5];

int cnt[maxn+5];
char c[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    scanf("%s",s+1);
    int tot=0;
    rep(i,1,n)
    {
        if(s[i]==c[tot]) cnt[tot]++;
        else c[++tot]=s[i],cnt[tot]=1;
    }
    int ans=0,G=0;
    rep(i,1,tot) if(c[i]=='G') G++;
    rep(i,1,tot) if(c[i]=='G') ans=max(ans,cnt[i]);
    if(G>=2) ans++;
    rep(i,1,tot) if(c[i]=='S' && cnt[i]==1 && i>1 && i<tot)
    {
        if(G>2) ans=max(ans,cnt[i-1]+1+cnt[i+1]);
        else if(G==2) ans=max(ans,cnt[i-1]+cnt[i+1]);
        else assert(0);
    }
    printf("%d\n",ans);
    return 0;
}