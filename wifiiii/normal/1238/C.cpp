
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

int a[500005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int h,n;
        cin>>h>>n;
        ii cin>>a[i];
        a[n+1] = 0;
        int ans = 0;
        int i = 1;
        while(i<=n)
        {
            if(i+1<=n && a[i+2] < a[i+1]-1) ans++, ++i;
            else i+=2;
        }
        cout<<ans<<endl;
    }
}