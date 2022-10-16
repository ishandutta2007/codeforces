#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    scanf("%s",s+1);
    ll ans=1;
    int l=1,r=n;
    while(s[l+1]==s[l]) l++;
    while(s[r-1]==s[r]) r--;
    ans+=l;
    ans+=n-r+1;
    if(s[1]==s[n]) ans+=1ll*l*(n-r+1);
    printf("%I64d\n",ans%mod);
    return 0;
}