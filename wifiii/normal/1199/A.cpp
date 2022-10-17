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
    int n,x,y;
    cin>>n>>x>>y;
    ii cin>>a[i];
    ii
    {
        int ok = 1;
        for(int j=max(1,i-x);j<=min(n,i+y);++j)
        {
            if(i==j) continue;
            if(a[j] <= a[i]) ok = 0;
        }
        if(ok) return cout<<i<<endl,0;
    }
}