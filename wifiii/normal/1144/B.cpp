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

vector<int> v[2];
int main()
{
    int n;
    cin>>n;
    ii
    {
        int tmp;
        cin>>tmp;
        v[tmp%2].push_back(tmp);
    }
    sort(all(v[0]));
    sort(all(v[1]));
    if(v[0].size() > v[1].size()) swap(v[0],v[1]);
    int m = v[1].size() - v[0].size();
    ll ans=0;
    for(int i=0;i<m-1;++i) ans+=v[1][i];
    cout<<ans<<endl;
}