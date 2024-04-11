//template start//
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
typedef double dd;
typedef long long ll;
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
template<typename T>
void printvector(vector<T>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<"\n";
}
template<typename T>
void printarray(T a[])
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" "; 
    }
    cout<<"\n";
}
 
void printpairs(vector<pair<int,int>>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i].F<<','<<v[i].S<<'|';
    }
    cout<<endl;
}
 
void print2d(vector<vector<int>>&v){
    for(int i=0;i<v.size();i++){
        printvector(v[i]);
    }
}
#define TT int T;cin>>T;for(int tt=1;tt<=T;tt++)
//template ends//
char a[1005][1005]={0};
void dfs(int x,int y,int n,int m)
{
    //cout<<n<<m<<"\n";
    if(a[x][y]!='#') return;
    a[x][y]='.';
    dfs(x-1,y,n,m);
    dfs(x+1,y,n,m);
    dfs(x,y-1,n,m);
    dfs(x,y+1,n,m);
}
int main()
{

    fast;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    bool whiterow=false,whitecolumn=false;
    for(int i=0;i<n;i++)
    {
        bool blackpresent=false,whiteafterblack=false;
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='#')
            {
                blackpresent=true;
                if(whiteafterblack) {cout<<-1;return 0;}
            }
            else
            {
                if(blackpresent) whiteafterblack=true;
            }
        }
        if(!blackpresent) whiterow=true;
    }
    for(int i=0;i<m;i++)
    {
        bool blackpresent=false,whiteafterblack=false;
        for(int j=0;j<n;j++)
        {
            if(a[j][i]=='#')
            {
                blackpresent=true;
                if(whiteafterblack) {cout<<-1;return 0;}
            }
            else
            {
                if(blackpresent) whiteafterblack=true;
            }
        }
        if(!blackpresent) whitecolumn=true;
    }
    if(whiterow!=whitecolumn) {cout<<-1;return 0;}
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans+=a[i][j]=='#';
            dfs(i,j,n,m);
        }
    }
    cout<<ans<<"\n";
    
}