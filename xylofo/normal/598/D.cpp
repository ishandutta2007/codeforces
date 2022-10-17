
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define trav(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define allof(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

vector<string> mm;
vector<vector<int> > v;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void dfs(int x, int y, int z){
    if(v[x][y]!=-1)return;
    v[x][y]=z;
    rep(i,0,4){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(mm[xx][yy]!='*')dfs(xx,yy,z);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    mm.resize(n);
    v.resize(n,vi(m,-1));
    rep(i,0,n){
        cin>>mm[i];
    }
    int cnt=0;
    rep(i,0,n){
        rep(j,0,m){
            if(mm[i][j]=='.' && v[i][j]==-1)dfs(i,j,cnt++);
        }
    }
    vi ans(cnt,0);
    rep(x,0,n){
        rep(y,0,m) if(mm[x][y]=='.'){
            rep(i,0,4){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(mm[xx][yy]=='*')ans[v[x][y]]++;
            }
        }
    }
    rep(i,0,k){
        int x,y;
        cin>>x>>y;
        x--,y--;
        cout<<ans[v[x][y]]<<endl;
    }
    return 0;
}