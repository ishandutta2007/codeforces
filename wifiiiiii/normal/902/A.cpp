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

int a[105],b[105];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i]>>b[i];
    int mx = a[0];
    ii
    {
        if(mx < a[i])
        {
            cout << "NO" << endl;
            return 0;
        }
        mx = max(mx, b[i]);
        if(mx >= m)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}