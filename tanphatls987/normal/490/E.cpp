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

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

char s[10];
int n,a[N][10];
bool DFS(int cur,int pos,int larger){
    if (pos>8){
        if (larger){
            FOR(j,0,8) if (a[cur][j]==-1) a[cur][j]=s[j];
            return true;
        }
        return false;
    }
    //if (larger==-1) return false;
    if (a[cur][pos]!=-1){
        if (larger==0&&a[cur][pos]<a[cur-1][pos]) return false;
        if (DFS(cur,pos+1,larger||a[cur][pos]>a[cur-1][pos])) return true;
    }
    else{
        if (larger){
            FOR(i,a[cur][pos-1]==-inf,9){
                s[pos]=i;
                if (DFS(cur,pos+1,1)) return true;
            }
        }else {
            int low=0;
            if (a[cur][pos-1]==-inf) low=1;
            low=max(low,a[cur-1][pos]);
            FOR(i,low,9){
                s[pos]=i;
                if (DFS(cur,pos+1,i>a[cur-1][pos])) return true;
            }
        }
    }
    return false;
}
void solve(){
    int tmp=0;
    while (a[1][tmp]==-inf) tmp++;
    if (a[1][tmp]==-1) a[1][tmp]=1,tmp++;
    while (tmp<=8) {
        if (a[1][tmp]==-1) a[1][tmp]=0;
        tmp++;
    }
    FOR(i,2,n) if (!DFS(i,0,0)) {printf("NO");return;}
    printf("YES\n");
    FOR(i,1,n){
        FOR(j,0,8) if (a[i][j]!=-inf) printf("%d",a[i][j]);
        ENDL;
    }
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("\n%s",s);
        int v=strlen(s);
        FOR(j,0,8){
            if (j>8-v){
                if (s[j-9+v]=='?') a[i][j]=-1;
                else a[i][j]=s[j-9+v]-'0';
            }else a[i][j]=-inf;
        }
    }
    solve();
}