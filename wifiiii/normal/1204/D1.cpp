#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200005;
int t[maxn];
int l[maxn],r[maxn],sum[maxn],mk[maxn];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    for(int i=1;i<=n;++i)
        if(s[i-1]=='0') l[i]=l[i-1]+1;
        else l[i]=l[i-1];
    for(int i=n;i>=1;--i)
        if(s[i-1]=='1') r[i]=r[i+1]+1;
        else r[i]=r[i+1];
    for(int i=1;i<=n;++i) sum[i]=l[i]+r[i];
    int mx=-1;
    for(int i=n;i>=1;--i)
    {
        if(sum[i]>mx) mk[i]=1;
        mx=max(mx,sum[i]);
    }
    for(int i=1;i<=n;++i)
    {
        if(s[i-1]=='0') cout<<0;
        else if(s[i-1]=='1' && mk[i]) cout<<0;
        else cout<<1;
    }
    cout<<endl;
}