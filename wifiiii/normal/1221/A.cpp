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
 
int a[3000];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        memset(a,0,sizeof(a));
        int n;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            int t;
            cin>>t;
            if(t<=2048) a[t]++;
        }
        a[2] += a[1] / 2;
        a[4] += a[2] / 2;
        a[8] += a[4] / 2;
        a[16] += a[8] / 2;
        a[32] += a[16] / 2;
        a[64] += a[32] / 2;
        a[128] += a[64] / 2;
        a[256] += a[128] / 2;
        a[512] += a[256] / 2;
        a[1024] += a[512] / 2;
        a[2048] += a[1024] / 2;
        if(a[2048]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}