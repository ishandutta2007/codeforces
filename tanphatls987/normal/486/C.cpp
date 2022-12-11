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
const int N=1e5+10;

string s;
int n,pos;
void solve(){
    if (pos>n/2) pos=n-pos+1;
    int l=1,r=(n+1)/2;
    while (s[l-1]==s[n-l]&&l<n) l++;
    while (s[r-1]==s[n-r]&&r>0) r--;
    int ans=0;
    if (l<=r){
        FOR(i,l,r) ans+=min(abs(s[i-1]-s[n-i]),26-abs(s[i-1]-s[n-i]));
        ans+=min(abs(pos-l),abs(pos-r))+r-l;
    }
    cout<<ans;
}
int main(){
    cin>>n>>pos>>s;
    solve();
}