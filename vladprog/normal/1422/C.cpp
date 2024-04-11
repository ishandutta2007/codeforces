#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,MOD=1e9+7;

int a[N];
int pw[N];
int pref[N];
int prefsum[N];
int suff[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n=s.size();
    s="_"+s;
    for(int i=1;i<=n;i++)
        a[i]=s[i]-'0';
    pw[0]=1;
    for(int i=1;i<=n+10;i++)
        pw[i]=pw[i-1]*10%MOD;
    for(int i=1;i<=n;i++)
        pref[i]=(pref[i-1]*10+a[i])%MOD;
    for(int i=1;i<=n;i++)
        prefsum[i]=(prefsum[i-1]+pref[i])%MOD;
    for(int i=n;i>=1;i--)
        suff[i]=(suff[i+1]+a[i]*pw[n-i])%MOD;
    int ans=0;
    for(int r=1;r<=n;r++)
    {
        ans+=suff[r+1]*r;
        ans+=prefsum[r-1]*pw[n-r];
        ans%=MOD;
    }
    cout<<ans;
}