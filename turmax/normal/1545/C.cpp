#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=1e3+5;
bool ok[maxn][maxn];
int mt[maxn];
bool used[maxn];
vector <int> z;
vector <int> ml;
void getml()
{
    int o=1;for(;;++o) ml.push_back(o);
}
void dfs(int x)
{
    //cout<<x<<" x "<<endl;
    used[x]=true;
    for(auto h:z)
    {
        if(x!=h && !ok[x][h])
        {
            if(!used[mt[h]]) dfs(mt[h]);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <vector <int> > a(2*n);
        for(int i=0;i<2*n;++i) {a[i].resize(n);for(int j=0;j<n;++j) {cin>>a[i][j];a[i][j]--;}}
        for(int i=0;i<2*n;++i)
        {
            for(int j=0;j<=i;++j)
            {
                ok[i][j]=true;
                if(i==j) {ok[i][j]=false;break;}
                for(int k=0;k<n;++k) {ok[i][j]=(ok[i][j] && a[i][k]!=a[j][k]);if(!ok[i][j]) break;}
                ok[j][i]=ok[i][j];
            }
        }
        vector <int> d[n];
        for(int i=0;i<2*n;++i) d[a[i][0]].push_back(i);
        vector <int> ans;
        int res=1;
        while(true)
        {
            //cout<<" ytgrf "<<endl;
            bool ok1=false;
            for(int i=0;i<n;++i)
            {
                if(d[i].size()==1)
                {
                    ok1=true;
                    ans.push_back(d[i][0]);
                    d[i].clear();
                    for(int j=0;j<n;++j)
                    {
                        vector <int> z;
                        for(auto h:d[j]) if(ok[h][ans.back()]) z.push_back(h);
                        d[j]=z;
                    }
                    break;
                }
            }
            if(ok1) continue;
            if(ans.size()==n)
        {
            cout<<(res%p+p)%p<<endl;
            for(auto h:ans) cout<<h+1<<' ';
            cout<<endl;
            break;
        }
        z.clear();
        int o=0;
        for(int i=0;i<n;++i) if(d[i].size())
        {
            o=i;
            mt[d[i][0]]=d[i][1];mt[d[i][1]]=d[i][0];
            z.push_back(d[i][0]);z.push_back(d[i][1]);
        }
        if(d[o].size()!=0 && d[o].size()!=2) getml();
        //cout<<o<<" o "<<d[o].size()<<" sz "<<endl;
        bool f2=true;
        for(int i=0;i<n;++i) {bool f=true;if(d[i].size()) for(int j=0;j<d[i].size();++j)
        {
            int h=d[i][j];
            for(auto h2:z) used[h2]=false;
            dfs(h);
            if(used[mt[h]]) {d[i].erase(d[i].begin()+j);f=false;f2=false;break;}
        }
        if(!f) break;
        }
        if(!f2) continue;
        res*=2;res%=p;
        d[o].erase(d[o].begin());
    }
    }
    return 0;
}