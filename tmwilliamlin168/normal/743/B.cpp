#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	ll n, k;
	cin >> n >> k;
	cout << 1+__builtin_ctzll(k);
}