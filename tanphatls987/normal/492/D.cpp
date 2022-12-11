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
const int N=0;

int n,x,y,v;
int main(){
    scanf("%d%d%d",&n,&x,&y);
    while (n--){
        scanf("%d",&v);
        v%=(x+y);
        ll L=0,R=1LL*x*y,ans;
        while (L<=R){
            ll M=(L+R)>>1;
            if (M/y+M/x>=v){
                ans=M;
                R=M-1;
            }else L=M+1;
        }
        if (ans%x==0&&ans%y==0) printf("Both\n");
        else if (ans%x==0) printf("Vova\n");
        else printf("Vanya\n");
    }
}