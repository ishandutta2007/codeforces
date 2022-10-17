#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int t[400][4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    rep(i,0,4)rep(j,0,200)t[j][i]=-1;
    int n,m;
    cin>>n>>m;
    int x=0,y=0;
    rep(i,0,min(2*n,m)){
        t[x][y]=i+1;
        y++;
        if(y==2)y=0,x++;
    }
    x=0,y=0;
    rep(i,0,min(2*n,m-2*n)){
        t[x][y+2]=2*n+i+1;
        y++;
        if(y==2)y=0,x++;
    }
    rep(i,0,n){
        if(t[i][2]!=-1)cout<<t[i][2]<<" ";
        if(t[i][0]!=-1)cout<<t[i][0]<<" ";
        if(t[i][3]!=-1)cout<<t[i][3]<<" ";
        if(t[i][1]!=-1)cout<<t[i][1]<<" ";
    }
    cout<<endl;
    return 0;
}