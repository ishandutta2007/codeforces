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

const int inf=((1LL<<31)-1);
const int MOD=1e9+7;
const int N=0;

typedef long long ll;

double d,s,pos;
int n;
void findpos(){
    int r=floor(pos/s);
    double ext=pos-(r*s);
    switch (r%4){
        case 0:{
            printf("%lf 0",ext);
            break;
        }
        case 1:{
            printf("%lf %lf",s,ext);
            break;
        }
        case 2:{
            printf("%lf %lf",s-ext,s);
            break;
            }
        case 3:printf("0 %lf",s-ext);
    }ENDL;
    pos-=s*((r/4)*4);
}
void solve(){
    FOR(i,1,n){
        pos+=d;
        findpos();
    }
}
int main(){
    cin>>s>>d>>n;
    solve();
}