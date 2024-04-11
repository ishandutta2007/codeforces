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
const int N=0;

int main()
{
    int n,m,v,x,y;
    cin>>n>>m;
    int po=0,ne=0;
    FOR(i,1,n) {cin>>v;if (v==1) po++;else ne++;}
    while (m--){
        cin>>x>>y;
        if ((y-x-1)%2==0&&(y-x+1)/2<=min(po,ne)) cout<<1;else cout<<0;
        cout<<'\n';
    }
}