

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
 
const int maxn = 200005;
int a[maxn], b[maxn], ra[maxn], rb[maxn];
set<pair<int,int>> s;
int main()
{
    int n;
    cin>>n;
    ii
    {
        cin>>a[i];
        s.insert({i, a[i]});
        ra[a[i]] = i;
    }
    ii cin>>b[i];
    int ans=0;
    ii
    {
        auto p = s.lower_bound({ra[b[i]], b[i]});
        if(p == s.begin()) ++ans;
        s.erase(p);
    }
    cout<<n-ans<<endl;
}