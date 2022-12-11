#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
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

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

int a[N];
int gcd(int x,int y){
    while (y){
        int tmp=y;y=x%y;x=tmp;
    }return x;
}
int main(){
    int n,q;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    map<int,ll> ans;
    map<int,int> div;
    map<int,int> ndiv;
    FOR(i,1,n){
        ndiv.clear();
        for(auto &j:div) ndiv[gcd(j.X,a[i])]+=j.Y;
        ndiv[a[i]]++;
        swap(div,ndiv);
        for(auto &j:div) ans[j.X]+=j.Y;
    }
    scanf("%d",&q);
    while (q--){
        int x;
        scanf("%d",&x);
        printf("%I64d\n",ans[x]);
    }
}