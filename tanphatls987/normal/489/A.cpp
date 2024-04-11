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
const int N=3e3+10;

int n,a[N];
int main(){
    scanf("%d",&n);
    REP(i,0,n) scanf("%d",&a[i]);
    printf("%d\n",n);
    REP(i,0,n){
        int cur=i;
        REP(j,i+1,n) if (a[j]<a[cur]) cur=j;
        printf("%d %d\n",i,cur);
        swap(a[i],a[cur]);
    }
}