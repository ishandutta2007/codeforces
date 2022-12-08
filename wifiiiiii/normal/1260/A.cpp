#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
//random_device rng;
//mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;

int cnt[10005];
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<b;++i) cnt[i%a]++;
        ll ans=0;
        for(int i=0;i<a;++i) ans=ans+1ll*cnt[i]*cnt[i];
        cout<<ans<<endl;
    }
}