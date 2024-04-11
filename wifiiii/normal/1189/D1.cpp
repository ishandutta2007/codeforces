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

int d[200005];
int main()
{
    int n;
    cin>>n;
    fe(i,n-1)
    {
        int u,v;
        cin>>u>>v;
        d[u]++,d[v]++;
    }
    ii if(d[i]==2) return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
}