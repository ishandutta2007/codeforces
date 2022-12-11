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
const int N=3;

int p1[N]={0},p2[N]={0},pri1[N][N]={0},pri2[N][N]={0},a1,a2,b1,b2;
bool minimize(int &a,int b){
    if (a>b) a=b;else return false;
    return true;
}
void solve(){
    int ta1=a1,ta2=a2,tb1=b1,tb2=b2;
    while (ta1%2==0) p1[0]++,ta1/=2,pri1[0][0]++;
    while (ta1%3==0) p1[1]++,ta1/=3,pri1[0][1]++;
    while (tb1%2==0) p1[0]++,tb1/=2,pri1[1][0]++;
    while (tb1%3==0) p1[1]++,tb1/=3,pri1[1][1]++;
    while (ta2%2==0) p2[0]++,ta2/=2,pri2[0][0]++;
    while (ta2%3==0) p2[1]++,ta2/=3,pri2[0][1]++;
    while (tb2%2==0) p2[0]++,tb2/=2,pri2[1][0]++;
    while (tb2%3==0) p2[1]++,tb2/=3,pri2[1][1]++;
    if (1LL*ta1*tb1!=1LL*ta2*tb2) {
        printf("-1");
        return;
    }
    int ans=inf;
    ii re;
    FOR(i,0,p1[0]+p1[1]){
        if (p2[0]+p2[1]<i) break;
        FOR(j,0,p1[1]){
            if (j>p2[1]) break;
            if (p1[1]-j+p1[0]<i) break;
            if (p2[1]-j+p2[0]<i) continue;
            //printf("%d %d %d\n",i,j,p1[1]-j+p1[1]-j+p1[0]-i+p2[1]-j+p2[1]-j+p2[0]-i);
            if (minimize(ans,p1[1]-j+p1[1]-j+p1[0]-i+p2[1]-j+p2[1]-j+p2[0]-i)) re=ii(i,j);
        }
    }
    //printf("%d %d\n",re.X,re.Y);
    printf("%d\n",ans);
    FOR(i,1,p1[1]-re.Y) if (a1%3==0) a1=(a1/3)*2;else b1=(b1/3)*2;
    FOR(i,1,p2[1]-re.Y) if (a2%3==0) a2=(a2/3)*2;else b2=(b2/3)*2;
    FOR(i,1,p1[1]-re.Y+p1[0]-re.X) if (a1%2==0) a1/=2;else b1/=2;
    FOR(i,1,p2[1]-re.Y+p2[0]-re.X) if (a2%2==0) a2/=2;else b2/=2;
    printf("%d %d\n%d %d",a1,b1,a2,b2);
}
int main(){
    scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
    solve();
}