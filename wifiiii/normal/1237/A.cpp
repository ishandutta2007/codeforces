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
 
int a[20005],b[20005],f[20005];
int main()
{
    int n;
    cin>>n;
    ii cin>>a[i];
    ii if(a[i] & 1) f[i]=1;
    ii if(f[i]) b[i]=(a[i]+1)/2; else b[i]=a[i]/2;
    int sum=0;
    ii sum+=b[i];
    ii
    {
        if(!sum) break;
        if(f[i] && sum) b[i]--, sum--;
    }
    ii cout<<b[i]<<endl;
}