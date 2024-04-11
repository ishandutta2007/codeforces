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
const int d[7]={1869,6198,1896,1689,1986,1968,1698};
string s;
int h[10]={0};
int main(){
    cin>>s;
    for(auto& i:s) h[i-'0']++;
    h[1]--,h[6]--,h[8]--,h[9]--;
    if (count(h+1,h+10,0)==9){
        printf("%d",d[0]);
        FOR(i,1,h[0]) printf("0");
        return 0;
    }
    int cur=0;
    FORD(i,9,0) while (h[i]) {
        printf("%d",i);
        cur=(10*cur+i)%7;
        h[i]--;
    }
    printf("%d",d[cur]);
}