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
 
int ans[305][305];
int main()
{
    int n;
    cin>>n;
    int f=1,tp=0;
    for(int i=1;i<=n;i++)
    {
        if(f) for(int j=1;j<=n;++j) ans[j][i]=++tp;
        else for(int j=n;j>=1;--j) ans[j][i]=++tp;
        f=f^1;
    }
    ii {ji cout<<ans[i][j]<<" ";cout<<endl;}
}