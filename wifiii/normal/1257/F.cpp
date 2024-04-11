#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
int a[1005];
typedef unsigned long long ull;
void norm(vector<int> &v)
{
    int mx=2e9;
    for(int i:v) mx=min(mx,i);
    for(int &i:v) i-=mx;
}
void norM(vector<int> &v)
{
    int mx=-2e9;
    for(int i:v) mx=max(mx,i);
    for(int &i:v) i-=mx;
}
ull hsh(vector<int> v)
{
    ull ret=0;
    for(int i=0;i<v.size();++i) ret=ret*912841+512417+v[i];
    return ret;
}
unordered_map<ull, int> mp;
const int N = (1<<15)-1;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int k=0;k<(1<<15);++k)
    {
        vector<int> v(n);
        for(int i=0;i<n;++i) v[i]=__builtin_popcount(k^(a[i]&N));
        norM(v);
        for(int &i:v) i=-i;
        ull tmp=hsh(v);
        mp[tmp]=k;
    }
    for(int k=0;k<(1<<15);++k)
    {
        vector<int> v(n);
        for(int i=0;i<n;++i) v[i]=__builtin_popcount(k^((a[i]>>15)&N));
        norm(v);
        ull tmp=hsh(v);
//        cout<<tmp<<endl;
        if(mp.count(tmp))
        {
            int ans = ((k<<15) | mp[tmp]);
            cout<<ans<<endl;
//            bitset<30> bs(ans);
//            cout << ans << " " << bs << endl;
//            for(int i=0;i<n;++i) cout<<__builtin_popcount(ans^a[i])<<" ";cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}