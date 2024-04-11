#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e3+5;
int dst[maxn][maxn];
string a[maxn];
int n,m;
void getans(pair <int,int> u,pair <int,int> v)
{
    if(u!=v)
    {
        cout<<u.first+1<<' '<<u.second+1<<' '<<v.first+1<<' '<<v.second+1<<endl;
        exit(0);
    }
    for(int i=0;i<n;++i) for(int j=0;j<m;++j)
    {
        if(u!=make_pair(i,j) && a[i][j]!='X')
            {
                cout<<u.first+1<<' '<<u.second+1<<' '<<i+1<<' '<<j+1<<endl;
                exit(0);
            }
    }
}
bool cou(vector <pair<int,int> > v,pair <int,int> o)
{
    for(auto h:v) if(h==o) return true;
    return false;
}
vector <pair<int,int> > in(vector <pair<int,int> > v1,vector <pair<int,int> > v2)
{
    sort(v1.begin(),v1.end());
    vector <pair<int,int> > ans;
    for(auto h:v2) if(upper_bound(v1.begin(),v1.end(),h)-lower_bound(v1.begin(),v1.end(),h)) ans.push_back(h);
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef LOCAL
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif // LOCAL
    int d;
    cin>>n>>m>>d;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int sum=0;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) {if(a[i][j]=='R') ++sum;}
    if(sum>300) {cout<<(-1);return 0;}
    vector <vector <pair<int,int> > > v;
    vector <pair<int,int> > l;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[i][j]=='R')
            {
                l.push_back({i,j});
                for(int i=0;i<n;++i) for(int j=0;j<m;++j) dst[i][j]=1e9;
                queue<pair<int,int> > z;
                z.push({i,j});dst[i][j]=0;
                vector <pair<int,int> > f;
                while(!z.empty())
                {
                    pair <int,int> o=z.front();z.pop();
                    f.push_back(o);
                    int x=o.first;int y=o.second;
                    int val=dst[x][y];
                    if(val==d) continue;
                    if(x>=1 && a[x-1][y]!='X' && dst[x-1][y]==1e9)
                    {
                        z.push({x-1,y});dst[x-1][y]=val+1;
                    }
                    if(x<n-1 && a[x+1][y]!='X' && dst[x+1][y]==1e9)
                    {
                        z.push({x+1,y});dst[x+1][y]=val+1;
                    }
                    if(y>=1 && a[x][y-1]!='X' && dst[x][y-1]==1e9)
                    {
                        z.push({x,y-1});dst[x][y-1]=val+1;
                    }
                    if(y<m-1 && a[x][y+1]!='X' && dst[x][y+1]==1e9)
                    {
                        z.push({x,y+1});dst[x][y+1]=val+1;
                    }
                }
                v.push_back(f);
            }
        }
    }
    vector <pair<int,int> > cur;
    bool flag=false;
    for(auto h:v[0])
    {
        flag=false;
        //if(h==make_pair(1LL,2LL)) cout<<" yhtgrf3 "<<endl;
       // cout<<h.first+1<<' '<<h.second+1<<endl;
        for(int i=1;i<v.size();++i)
        {
            //if(h==make_pair(1LL,2LL)) {if(!cou(v[i],h) && !cou(v[i],{5,8})) cout<<l[i].first+1<<' '<<l[i].second+1<<" ban "<<endl;}
            if(!cou(v[i],h))
            {
                 if(!flag) {flag=true;cur=v[i];continue;}
                 else {cur=in(cur,v[i]);}
            }
        }
        if(flag && cur.empty()) continue;
        else if(flag)
        {
            getans(h,cur[0]);
        }
        else
        {
            getans(h,h);
        }
    }
    cout<<(-1);
    return 0;
}