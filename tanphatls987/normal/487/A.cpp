#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

int a[2][3],c[3];
void solve(){
    int ans=inf;
    FOR(turn,1,100){
        int mon=0,patk=(a[1][0]+turn-1)/turn,cur=inf;
        mon+=max(0,a[1][2]+patk-a[0][1])*c[1];
        FOR(def,a[0][2],100){
            int dec=max(a[1][1]-def,0),hp=max(0,dec*turn+1-a[0][0]),cost=(def-a[0][2])*c[2]+hp*c[0];
            cur=min(cur,cost);
        }
        ans=min(ans,mon+cur);
    }
    cout<<ans;
}
int main(){
    FOR(i,0,1)
        FOR(j,0,2) scanf("%d",&a[i][j]);
    FOR(j,0,2) scanf("%d",c+j);
    solve();
}