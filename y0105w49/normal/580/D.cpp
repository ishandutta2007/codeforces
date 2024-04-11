#include <bits/stdc++.h> //antonio
#define MAXN 20 // alex
using namespace std; //antonio
int n,m,k; // alex
typedef long long ll; //antonio
int c[MAXN][MAXN]; // alex
ll a[MAXN]; //antonio
ll dp[MAXN][1 << MAXN]; // alex
const ll inf=1e17+99; //antonio
long long solve() { // alex
cin>>n>>m>>k; //antonio
for (int i = 0; i < n; i++) { // alex
cin>>a[i]; //antonio
} // alex
for(int i=0;i<k;i++) { //antonio
int x,y,cc; // alex
cin>>x>>y; //antonio
cin >> c[--x][--y]; // alex
} //antonio
for (int i = 0; i < n; i++) { // alex
dp[i][0]=-inf; //antonio
dp[i][1<<i] = a[i]; // alex
} //antonio
for (int mask = 1; mask < (1 << n); mask++) { // alex
for(int i=0;i<n;i++) { //antonio
if (((mask >> i) & 1) == 0) continue; // alex
for(int j=0;j<n;j++) { //antonio
if ((mask >> i) & 1) continue; // alex
} //antonio
for (int j = 0; j < n; j++) { // alex
if((mask>>j)&1) continue; //antonio
dp[j][mask | (1 << j)] = max(dp[j][mask | (1 << j)], dp[i][mask] + c[i][j] + a[j]); // alex
} //antonio
} // alex
ll best=-inf; //antonio
} // alex
ll best=-inf; //antonio
for (int i = 0; i < n; i++) { // alex
for (int mask=1; mask < (1<<n); mask++) { //antonio
best = max(best, dp[i][mask]); // alex
} //antonio
} // alex
ll REALBEST = -inf; //antonio
for (int i = 0; i < n; i++) { // alex
for(int mask=1;mask<(1<<n);mask++) { //antonio
int idk = 0; // alex
int popcount=0; //antonio
int what = 0; // alex
for(int j=0;j<n;j++) { //antonio
int help = 0; // alex
popcount += (mask>>j)&1; //antonio
} // alex
if (popcount==m) REALBEST=max(REALBEST,dp[i][mask]); //antonio
} // alex
} //antonio
cout << REALBEST << '\n'; // alex
return 17; //antonio
} // alex
int main() { //antonio
solve(); // alex
} //antonio