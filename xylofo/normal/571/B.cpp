#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define FOR(it,st,en) for(int it=(st);it<(int)(en);++it)
#define REP(it,en) FOR(it,0,en)
#define ITE(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define ALLOF(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define X first
#define Y second
typedef long long int LL; 
typedef long double LD;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
const LL INF=(LL)1e18; 
const double EPS=(LD)1e-7;

int n,k;
VI a,c;
VVI dp;
LL sm(int a,int b){
    if(b>n)return INF;
    return c[b-1]-c[a];
}
LL solve(int p, int l,int l2){
    LL ans=0;
    if(l<0)return INF;
    if(l2<0)return INF;
    if(p==n)return l==0?0:INF;
    if(p>n)return INF;
    if(dp[l][l2]!=-1)return dp[l][l2];
    return dp[l][l2]=min(sm(p,p+n/k)+solve(p+n/k,l,l2-1),sm(p,p+n/k+1)+solve(p+n/k+1,l-1,l2));

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>k;
    a.assign(n,0);
    c.assign(n+1,0);
    dp.assign(k+1,VI(k+1,-1));
    REP(i,n)cin>>a[i];
    sort(ALLOF(a));
    FOR(i,1,n)c[i]=abs(a[i]-a[i-1])+c[i-1];
    cout<<solve(0,n%k,k-n%k)<<endl;
	return 0;
}