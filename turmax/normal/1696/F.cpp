#include <bits/stdc++.h>

using namespace std;
#define int long long
const int sz=105;
const int maxn=105*105;
int par[maxn];int sz1[maxn];bool t[sz][sz][sz];int d[sz][sz];
int get(int x)
{
    if(par[x]==(-1)) return x;
    int ans=get(par[x]);par[x]=ans;return ans;
}
void merg(int x,int y)
{
     x=get(x);y=get(y);if(x==y) return;
     par[x]=y;sz1[y]+=sz1[x];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t1;cin>>t1;
    while(t1--)
    {
        for(int i=0;i<maxn;++i) {par[i]=(-1);sz1[i]=1;}
        int n;cin>>n;int sz2=(n+1)*sz;
        for(int i=0;i<n-1;++i)
        {
            for(int j=0;j<n-i-1;++j)
            {
                string s;cin>>s;
                for(int k=0;k<n;++k)
                {
                    int x=i;int y=i+j+1;int z=k;
                    t[x][y][z]=(s[k]=='1');t[y][x][z]=(s[k]=='1');
                    if(s[k]=='1')
                    {
                        merg(min(x,z)*sz+max(x,z),min(y,z)*sz+max(y,z));
                    }
                }
            }
        }
        bool ok1=false;
        for(int i=0;i<sz2;++i)
        {
            if(par[i]==(-1) && sz1[i]==(n-1))
            {
                vector<pair<int,int> > v;
                for(int j=0;j<sz2;++j)
                {
                    if(get(j)==i)
                    {
                        int v1=j/sz;int v2=j%sz;
                        if(v1>v2) swap(v1,v2);
                        v.push_back({v1,v2});
                    }
                }
                if(v.size()!=(n-1)) continue;
                bool ok=true;
                for(int i=0;i<n;++i) for(int j=0;j<n;++j) {d[i][j]=1e9;if(i==j) d[i][j]=0;}
                for(auto h:v) {d[h.first][h.second]=1;d[h.second][h.first]=1;}
                for(int i=0;i<n;++i) for(int j=0;j<n;++j) for(int k=0;k<n;++k) d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
                for(int i=0;i<n;++i) for(int j=0;j<n;++j) if(d[i][j]==1e9) {ok=false;}
                if(!ok) continue;
                for(int x=0;x<n;++x)
                {
                    if(!ok) break;
                    for(int y=x+1;y<n;++y)
                    {
                        if(!ok) break;
                        for(int z=0;z<n;++z)
                        {
                            if(t[x][y][z]!=(d[x][z]==d[y][z])) {ok=false;break;}
                        }
                    }
                }
                if(!ok) continue;
                ok1=true;
                cout<<"Yes"<<'\n';
                for(auto h:v) cout<<h.first+1<<' '<<h.second+1<<'\n';
                break;
            }
        }
        if(!ok1)
        {
            cout<<"No"<<'\n';
        }
    }
    return 0;
}