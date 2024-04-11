#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[2000005];
int main()
{
    int n;
    cin>>n;
    if(n%2==0) return cout<<"NO\n",0;
    cout<<"YES"<<endl;
    int f=1;
    for(int i=1;i<=n;++i)
    {
        if(f==1) a[i]=i*2-1;
        else a[i]=i*2;
        a[i+n]=a[i]+f;
        f=-f;
    }
    for(int i=1;i<=2*n;++i) cout<<a[i]<<" ";cout<<endl;
}