#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e6+5;
vector <int> v[maxn];
bool used[maxn];
set <vector <int> > z;
int arr[maxn];
mt19937_64 rnd;
void init()
{
    used[0]=true;used[1]=true;
    for(int i=2;i<maxn;++i)
    {
        if(used[i]) continue;
        for(int j=i;j<maxn;j+=i)
        {
            used[j]=true;
            int o=1;int j1=j;while(j1%i==0) {++o;j1/=i;}
            v[j].push_back(o);
        }
    }
    for(int j=1;j<maxn;++j) {sort(v[j].begin(),v[j].end());reverse(v[j].begin(),v[j].end());z.insert(v[j]);}
}
map <pair<int,int>,vector <int> > uto;
int f(vector <int> v)
{
    int ans=1;for(auto h:v) ans*=h;
    return ans;
}
int ha(vector <int> v)
{
    int has=0;
    for(int i=0;i<v.size();++i) has+=arr[i]*v[i];
    return has;
}
vector <int> to(vector <int> v,int n)
{
    if(n==0) {return {f(v)};}
    int has=ha(v);
    if(uto.count({has,n})) return uto[{has,n}];
    vector <int> res;
    for(int i=0;i<v.size();++i)
    {
        vector <int> g=v;
        g[i]--;
        sort(g.begin(),g.end());reverse(g.begin(),g.end());if(g.back()<=1) g.pop_back();
        vector <int> res1=to(g,n-1);
        for(auto h:res1) res.push_back(h);
    }
    for(int i=0;i<v.size();++i)
    {
        vector <int> g=v;
        g[i]++;
        sort(g.begin(),g.end());reverse(g.begin(),g.end());
        vector <int> res1=to(g,n-1);
        for(auto h:res1) res.push_back(h);
    }
    vector <int> g=v;
    g.push_back(2);
    sort(g.begin(),g.end());reverse(g.begin(),g.end());
    vector <int> res1=to(g,n-1);
    for(auto h:res1) res.push_back(h);
    sort(res.begin(),res.end());res.erase(unique(res.begin(),res.end()),res.end());
    uto[{has,n}]=res;
    return res;
}
map <pair<vector<int>,vector <int> >,int> u;
int slv(vector <int> v1,vector <int> v2)
{
    if(u.count({v1,v2})) return u[{v1,v2}];
    if(u.count({v2,v1})) return u[{v2,v1}];
    vector <int> u1[11];vector <int> u2[11];
    for(int i=0;i<=10;++i) u1[i]=uto[{ha(v1),i}];
    for(int i=0;i<=10;++i) u2[i]=uto[{ha(v2),i}];
    //cout<<u1[0].size()<<' '<<u2[0].size()<<endl;
    //for(auto h:u1[0]) cout<<h<<" h1 "<<endl;
    //for(auto h:u2[0]) cout<<h<<" h2 "<<endl;
    for(int s=0;s<=20;++s)
    {
        for(int i=max(0LL,s-10);i<=min((int) 10,s);++i)
        {
            int j=s-i;
            int l=0,r=0;
            while(l<u1[i].size() && r<u2[j].size())
            {
                if(u1[i][l]==u2[j][r])
                {
                    u[{v1,v2}]=s;
                    return s;
                }
                else if(u1[i][l]<u2[j][r]) ++l;
                else ++r;
            }
        }
    }
    assert(false);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxn;++i) arr[i]=rnd();
    init();
    for(auto h:z) {uto[{ha(h),0}]={f(h)};}
    for(auto h:z) to(h,10);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        vector <int> v1=v[a];vector <int> v2=v[b];
        cout<<slv(v1,v2)<<'\n';
    }
    return 0;
}