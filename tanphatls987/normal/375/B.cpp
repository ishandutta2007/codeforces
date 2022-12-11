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
const int N=5e3+10;

int h[N]={0},n,m,head,tail;
ii l[N];
char s[N][N];
int maximize(int &a,int b){
    if (a<b) a=b;
}
void init(){
    FOR(i,0,n+1) l[i]=ii(i-1,i+1);
    head=1;tail=n;
}
void solve(){
    int ans=0;
    REP(j,0,m){
        FOR(i,1,n){
            if (s[i][j]=='1') h[i]++;
            else {
                h[i]=0;
                if (i==tail) continue;
                if (i==head) head=l[i].Y;
                l[l[i].X].Y=l[i].Y;
                l[l[i].Y].X=l[i].X;
                l[i]=ii(tail,n+1);
                l[tail].Y=i;
                tail=i;
            }
        }
        int cur=head;
        FOR(i,1,n){
            maximize(ans,h[cur]*i);
            cur=l[cur].Y;
        }
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("\n%s",s[i]);
    init();
    solve();
}