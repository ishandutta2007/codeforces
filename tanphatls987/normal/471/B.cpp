#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
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

const int inf=((1LL<<31)-1);
const int MOD=1e9+7;
const int N=2e3+10;

int n,v,a[N]={0},h[3][N];
vector <int> p[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",&a[i]);
        p[a[i]].push_back(i);
    }
}
void solve(){
    ll way=1;
    FOR(i,1,2001) if (p[i].size()>0){
        way*=p[i].size();
        if (way>=3) break;
    }
    if (way<3) {printf("NO");return;}
    printf("YES\n");
    int top=0;
    FOR(i,1,2000)
        REP(j,0,p[i].size()) h[0][++top]=p[i][j];
    FOR(i,1,n) h[1][i]=h[0][i],h[2][i]=h[0][i];
    int t=1;
    FOR(i,1,n){
        if (p[a[h[0][i]]].size()>=3){
            swap(h[1][i],h[1][i+1]);
            swap(h[2][i],h[2][i+2]);
            break;
        }
        if (p[a[h[0][i]]].size()==2){
            swap(h[t][i],h[t][i+1]);t++;i++;
            if (t>2) break;
        }
    }
    FOR(i,1,n) printf("%d ",h[0][i]);ENDL;
    FOR(i,1,n) printf("%d ",h[1][i]);ENDL;
    FOR(i,1,n) printf("%d ",h[2][i]);
}
int main(){
    prepare();
    solve();
}