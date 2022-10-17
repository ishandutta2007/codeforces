
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


int mx[11],vis[11];
ll ans[11][11];
void precal(int x,int y)
{
    memset(mx,0x3f,sizeof(mx));
    for(int i=0;i<=200;++i)
    {
        for(int j=0;j<=200;++j)
        {
            if(!i && !j) continue;
            int tmp = (x*i+y*j)%10;
            mx[tmp] = min(mx[tmp], i+j);
        }
    }
}
int a[2000005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int n = s.size()-1;
    for(int i=0;i<n;++i) a[i]=(s[i+1]-s[i]+10)%10;
    for(int i=0;i<10;++i)
    {
        for(int j=i;j<10;++j)
        {
            precal(i,j);
            int ok = 1;
            ll res = 0;
            for(int i=0;i<n;++i)
            {
                if(mx[a[i]]>1e9) {ok=0;break;}
                res+=mx[a[i]];
            }
            if(ok) ans[i][j]=res-n;
            else ans[i][j]=-1;
        }
    }
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
        {
            if(i>j) cout<<ans[j][i]<<" ";
            else cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}