#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

vector<int> ls[55];
int tmp[10005];
bool vis[10005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m,n;
    cin>>m>>n;
    rep(i,m)
    {
        memset(vis,0,sizeof(vis));
        int t;
        cin>>t;
        rep(j,t) cin>>tmp[j],vis[tmp[j]]=1;
        sort(tmp+1,tmp+1+t);
        rep(j,i-1)
        {
            int I = 0, J = 1;
            while(I<ls[j].size() && J<=t)
            {
                if(tmp[J]==ls[j][I]) I++,J++;
                else I++;
            }
            if(J>t)
            {
                cout << "impossible" << endl;
                return 0;
            }
        }
        rep(j,n) if(!vis[j]) ls[i].push_back(j);
    }
    cout<<"possible"<<endl;
}