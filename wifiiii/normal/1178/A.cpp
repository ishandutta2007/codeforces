
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

int a[105];
vector<int> ans;
int main()
{
    int n;
    cin>>n;
    int sum=0,tot=0;
    ii cin>>a[i],sum+=a[i];
    ans.push_back(1);
    tot+=a[1];
    for(int i=2;i<=n;++i) if(a[i]*2<=a[1]) ans.push_back(i),tot+=a[i];
    if(tot<=sum-tot) {cout<<0<<endl;return 0;}
    cout<<ans.size()<<endl;
    for(int i:ans) cout<<i<<" ";cout<<endl;
}