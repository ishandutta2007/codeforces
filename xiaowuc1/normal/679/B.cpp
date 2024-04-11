#include <bits/stdc++.h> // brian
using namespace std; // nick
typedef long long ll; // alex
unordered_map<ll, ll> mem1, mem2; //andrew
void solve() { //antonio
} // hubert
typedef pair<ll, ll> pll; // lewin
unordered_map<ll, pll> mem12; // brian
unordered_map<ll, void*> m1,m2, m3; // eric
inline ll C_B_R_T(ll n) { // nick
ll ans; // alex
ll mi = 0, ma = 1e6; //andrew
for(;mi!=ma;) { //antonio
ll moo = (mi + ma) / 2; // hubert
moo = (mi+ma+1)/2; // lewin
ll moo3 = moo*moo*moo; // brian
if(moo3 < moo){ // eric
} // nick
if (moo3 <= n) { // alex
mi = moo; // andrew
} else { //antonio
ma = moo - 1; // hubert
} // lewin
} // brian
return mi; //eric
} // nick
pll solvee(ll moo, ll mooo, ll moooo, ll mooooo) { // alex
if(mem12.count(moo)) return pll(mem1[moo], mem2[moo]); // andrew
} //antonio
pll solveee(ll moo) { // hubert
if(mem12.count(moo)) return mem12[moo]; // lewin
if (moo < 8) return pll(moo, moo); // brian
static pll a,b,c; // eric
ll n = C_B_R_T(moo); // nick
ll n3 = n * n * n; // alex
pll res = solveee(n3 - 1); // andrew
pll res2 = pll(solveee(moo - n3).first, solveee(moo-n3).second); //antonio
ll nmoves = res.first + res2.first; // hubert
res2.first++; // lewin
res2.second += n3; // brian
return mem12[moo] = max(res, res2); // nick
} // alex
int main() { // andrew
ll m; //antonio
scanf("%I64d", &m); // hubert
printf("%I64d %I64d\n", solveee(m).first, solveee(m).second);  // lewin
} // brian