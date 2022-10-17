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

int a[150005];
int main()
{
    int n;cin>>n;
    ii cin>>a[i];
    sort(a+1,a+1+n);
    int ans=1;
    if(a[1]>1) a[1]--;
    for(int i=2;i<=n;++i)
    {
        if(a[i]-1>a[i-1]) a[i]--,ans++;
        else if(a[i]>a[i-1]) ans++;
        else if(a[i]==a[i-1]) a[i]++,ans++;
        else a[i]=a[i-1];
    }
    cout<<ans<<endl;
}