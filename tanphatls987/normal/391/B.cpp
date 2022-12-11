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
const int N=1e3+10;

typedef long long ll;
typedef pair<int,int> ii;

string s;
int n;
vector <int> a[30];
int f[N]={0};
void prepare(){
    cin>>s;
    n=s.length();
    FOR(i,1,s.length()) a[s[i-1]-'A'].push_back(i);
}
void solve(){
    FOR(i,0,'Z'-'A')
        REP(j,1,a[i].size())
            REP(k,0,j) if ((a[i][j]-a[i][k])%2) f[a[i][j]]=max(f[a[i][j]],f[a[i][k]]+1);
    cout<<*max_element(f+1,f+n+1)+1;
}
int main(){
    prepare();
    solve();
}