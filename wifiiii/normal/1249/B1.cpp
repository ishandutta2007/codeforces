#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 urng(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[200005],vis[200005],ans[200005];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        ii cin>>a[i];
        ii vis[i]=0;
        ii
        {
            if(vis[i]) continue;
            int p = i;
            int cnt = 0;
            vector<int> tmp;
            while(!vis[p])
            {
                tmp.push_back(p);
                vis[p] = 1;
                p = a[p];
                ++cnt;
            }
            for(int i:tmp) ans[i]=cnt;
        }
        ii cout<<ans[i]<<" ";cout<<endl;
    }
}