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

int a[1005][1005];
int vis[1000005];
int main()
{
    int n;
    cin>>n;
    int tot=0;
    for(int i=0;i<n;++i)
    {
        while(vis[tot]) ++tot;
        a[0][i] = tot++;
        for(int j=1;j<n;++j) a[j][i]=a[j-1][i]+4,vis[a[j][i]]=1;
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}