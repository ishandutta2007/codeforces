
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 100005;
ll a[maxn], b[maxn];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ii cin>>a[i];
    ii cin>>b[i];
    if(a[1]!=b[1] || a[n]!=b[n]) return cout<<"No"<<endl,0;
    vector<ll> v1,v2;
    for(int i=1;i<=n-1;++i) v1.push_back(a[i]-a[i+1]),v2.push_back(b[i]-b[i+1]);
    sort(all(v1));sort(all(v2));
    if(v1!=v2) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}