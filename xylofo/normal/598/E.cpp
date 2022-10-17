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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vvi> dp(51,vvi(31,vi(31,INF)));
    rep(x,0,31){
        rep(y,0,31){
            dp[0][x][y]=0;
        }
    }
    rep(k,1,51){
        rep(x,1,31){
            rep(y,x,31){ //y>=x
                if(x*y==k) dp[k][x][y]=0;
                else{
                    int& cur=dp[k][x][y];
                    rep(nx,1,x/2+1){
                        int mx=x-nx;
                        rep(nk,0,k+1){
                            cur=min(cur,y*y+dp[nk][min(nx,y)][max(nx,y)] + dp[k-nk][min(mx,y)][max(mx,y)]);
                        }
                    }
                    rep(ny,1,y/2+1){
                        int my=y-ny;
                        rep(nk,0,k+1){
                            cur=min(cur,x*x+dp[nk][min(ny,x)][max(ny,x)] + dp[k-nk][min(my,x)][max(my,x)]);
                        }
                    }
                }
            }
        }
    }
    int t;
    cin>>t;
    rep(i,0,t){
        int n,m,k;
        cin>>n>>m>>k;
        cout<<dp[k][min(n,m)][max(n,m)]<<endl;
    }
    return 0;
}