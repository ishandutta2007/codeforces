#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e2+10;

int n,a[N];
int main(){
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    int ma=*max_element(a+1,a+n+1),mi=*min_element(a+1,a+n+1);
    int L=1,R=n;
    while (a[L]!=ma) L++;
    while (a[R]!=mi) R--;
    cout<<(L-1)+(n-R)-(L>R);
}