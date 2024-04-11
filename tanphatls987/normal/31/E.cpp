#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("d.inp","r",stdin)
#define OUTPUT freopen("d.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=40;

ull f[N][N],p10[N]={0};
string s;
int ans[N]={0},t[N][N],n;
bool maximize(ull &a,ull b){
    if (a<b) a=b;else return false;
    return true;
}
void solve(){
    p10[0]=1;
    FOR(i,1,18) p10[i]=10*p10[i-1];
    f[0][0]=0;
    FOR(i,1,n<<1){
        FOR(j,max(i-n,0),min(n,i)){
            if (j<i) {
                f[i][j]=f[i-1][j]+p10[n-(i-j)]*(s[i-1]-'0');
                t[i][j]=j;
            }else{
                f[i][j]=f[i-1][j-1]+p10[n-j]*(s[i-1]-'0');
                t[i][j]=j-1;
            }
            if (j>0&&maximize(f[i][j],f[i-1][j-1]+p10[n-j]*(s[i-1]-'0'))) t[i][j]=j-1;
            //printf("%d %d %d %llu\n",i,j,t[i][j],f[i][j]);
        }
    }
    int x=n;
    FORD(i,2*n,1){
        if (t[i][x]==x-1) ans[i]=1;
        x=t[i][x];
    }
    FOR(i,1,2*n) if (ans[i]) printf("H");else printf("M");
}
int main(){
    cin>>n>>s;
    solve();
}