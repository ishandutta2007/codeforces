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

int a[100005];
int main()
{
    int n;
    cin>>n;
    ii cin>>a[i];
    sort(a+1,a+1+n);
    if(a[n-2]+a[n-1]<=a[n]) return cout<<"NO"<<endl,0;
    vector<int> ans;
    ans.push_back(a[n-1]);
    ans.push_back(a[n]);
    ans.push_back(a[n-2]);
    for(int i=n-3;i>=1;--i) ans.push_back(a[i]);
    cout<<"YES"<<endl;
    for(int i:ans) cout<<i<<" ";cout<<endl;
}