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


int chk(int x)
{
    vector<int> vis(11);
    while(x)
    {
        if(vis[x%10]) return 0;
        vis[x%10]++;
        x/=10;
    }
    return 1;
}
int main()
{
    int l,r;
    cin>>l>>r;
    for(int i=l;i<=r;++i) if(chk(i)) return cout<<i<<endl,0;
    cout<<-1<<endl;
}