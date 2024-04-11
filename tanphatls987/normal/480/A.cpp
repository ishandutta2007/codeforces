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

int n;
ii a[N];
bool comp(ii a,ii b){
    if (a.X==b.X) return a.Y<b.Y;
    return a.X<b.X;
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    sort(a+1,a+n+1,comp);
    int cur=a[1].Y;
    FOR(i,2,n){
        if (a[i].Y>=cur) cur=a[i].Y;
        else cur=a[i].X;
    }
    printf("%d",cur);
}