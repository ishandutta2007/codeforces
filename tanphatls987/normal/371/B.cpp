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

int n,m,a[2];
int gcd(int x,int y){
    while (y){
        int tmp=y;y=x%y;x=tmp;
    }
    return x;
}
int main(){
    cin>>n>>m;
    int equ=gcd(n,m);
    a[0]=n/equ,a[1]=m/equ;
    int ans=0;
    FOR(i,0,1){
        while (a[i]%2==0) a[i]/=2,ans++;
        while (a[i]%3==0) a[i]/=3,ans++;
        while (a[i]%5==0) a[i]/=5,ans++;
        if (a[i]>1) {ans=-1;break;}
    }
    cout<<ans;
}