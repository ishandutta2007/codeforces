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

int cnt[200005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ii
    {
        int tmp;
        cin>>tmp;
        cnt[tmp]++;
    }
    for(int i=0;i<=200000;++i) if(cnt[i]>2) {cout<<"NO"<<endl;return 0;}
    vector<int> v1,v2;
    for(int i=0;i<=200000;++i) if(cnt[i]) cnt[i]--,v1.push_back(i);
    for(int i=200000;i>=0;--i) if(cnt[i]) cnt[i]--,v2.push_back(i);
    cout<<"YES"<<endl;
    cout<<v1.size()<<endl;
    for(int i:v1) cout<<i<<" ";cout<<endl;
    cout<<v2.size()<<endl;
    for(int i:v2) cout<<i<<" ";cout<<endl;
}