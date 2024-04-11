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
const int N=1e5+10;

string a[N][2];
int n,v,h[N];
void prepare(){
    cin>>n;
    FOR(i,1,n) cin>>a[i][0]>>a[i][1];
    FOR(i,1,n) if (a[i][0]>a[i][1]) swap(a[i][0],a[i][1]);
    FOR(i,1,n) cin>>h[i];
    //FOR(i,1,n) cout<<a[i][0]<<" "<<a[i][1]<<'\n';
}
void solve(){
    int last=0;
    FOR(i,2,n){
        int x=h[i],y=h[i-1];
        if (a[x][0]<a[y][last]){
            if (a[x][1]<a[y][last]) {cout<<"NO";return;}
            else last=1;
        }else last=0;
    }
    cout<<"YES";
}
int main(){
    prepare();
    solve();
}