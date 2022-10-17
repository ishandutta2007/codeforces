#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int lg[400005];
map<int,int> mp;
vector<int> v;
int sum[400005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    lg[1]=0;
    int n,k;
    cin>>n>>k;
    ii
    {
        int tmp;
        cin>>tmp;
        mp[tmp]++;
    }
    for(int i=2;i<=n;++i)
        if(__builtin_popcount(i-1) == 1) lg[i]=lg[i-1]+1;
        else lg[i]=lg[i-1];
    int K=n;
    for(;;K--)
        if(n*lg[K] <= 8*k) break;
    for(auto p:mp) v.push_back(p.second);
    if(K>=v.size()) return cout<<0<<endl,0;
    for(int i=0;i<v.size();++i) sum[i+1]=sum[i]+v[i];
    int ans=1e9;
    for(int i=0;i<=v.size();++i)
    {
        if(i+K >= v.size()) break;
        ans=min(ans,n-(sum[i+K]-sum[i]));
    }
    cout<<ans<<endl;
}