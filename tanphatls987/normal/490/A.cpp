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
const int N=0;

int n,v;
vector <int> a[5];
int main(){
    cin>>n;
    FOR(i,1,n){
        cin>>v;
        a[v].push_back(i);
    }
    int ans=min(min(a[1].size(),a[2].size()),a[3].size());
    printf("%d\n",ans);
    REP(i,0,ans){
        FOR(j,1,3) printf("%d ",a[j][i]);
        ENDL;
    }
}