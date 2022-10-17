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
int c[1005][105];
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    ii cin>>a[i]>>b[i];
    for(int i=1;i<=n;++i)
    {
        if(s[i-1] == '1') for(int j=0;j<=1000;++j) c[j][i]=1;
    }
    for(int i=1;i<=1000;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i-b[j]>=0 && (i-b[j])%a[j]==0) c[i][j]=1-c[i-1][j];
            else c[i][j]=c[i-1][j];
        }
    }
    int ans = 0;
    for(int i=0;i<=1000;++i)
    {
        int cnt = 0;
        for(int j=1;j<=n;++j) if(c[i][j]) cnt++;
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}