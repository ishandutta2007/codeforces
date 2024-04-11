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

int n,l,x,y,a[N];
void prepare(){
    scanf("%d%d%d%d",&n,&l,&x,&y);
    FOR(i,1,n) scanf("%d",a+i);
}
void solve(){
    int curx=0,cury=0;
    bool xok=false,yok=false;
    FOR(i,2,n){
        while (a[i]-a[curx]>x) curx++;
        while (a[i]-a[cury]>y) cury++;
        if (a[i]-a[curx]==x) xok=true;
        if (a[i]-a[cury]==y) yok=true;
    }
    if (xok&&yok) {printf("0");return;}
    if (xok||yok) {printf("1\n%d",xok?y:x);return;}
    curx=0;
    int cn=y-x;
    FOR(i,2,n){
        while (a[i]-a[curx]>cn) curx++;
        if (a[i]-a[curx]==cn){
            if (a[i]+x<=l){
                printf("1\n%d",a[i]+x);
                return;
            }
            if (a[curx]-x>=0){
                printf("1\n%d",a[curx]-x);
                return;
            }
        }
    }
    cn=y+x;curx=0;
    FOR(i,2,n){
        while (a[i]-a[curx]>cn) curx++;
        if (a[i]-a[curx]==cn){
            printf("1\n%d",a[i]-y);
            return;
        }
    }
    printf("2\n%d %d",x,y);
}
int main(){
    prepare();
    solve();
}