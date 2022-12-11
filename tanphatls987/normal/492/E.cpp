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
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e6+10;

int n,m,dx,dy,h[N],f[N]={0},x,y;
void prepare(){
    scanf("%d%d%d%d",&n,&m,&dx,&dy);
    int cur=0;h[0]=0;
    while ((cur+dx)%n){
        h[(cur+dx)%n]=h[cur]+1;
        cur=(cur+dx)%n;
    }
    //REP(i,0,n) printf("%d ",h[i]);ENDL;
    while (m--){
        scanf("%d%d",&x,&y);
        y=(y+1LL*dy*(n-h[x]))%n;
        //printf("%d\n",y);
        f[y]++;
    }
}
int main(){
    prepare();
    int ans=0;
    REP(i,0,n) if (f[i]>f[ans]) ans=i;
    printf("0 %d",ans);
}