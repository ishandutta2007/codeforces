#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pop pop_back
#define bigint int64_t
#define FORi(j) for(int i = 0; i < j; i++)
#define FORj(i) for(int j = 0; j < i; j++) 
#define FORir(j, r) for(int i = r; i < j; i++)
#define FORjr(i, r) for(int j = r; j < i; j++) 
#define setsize(i) bigint(i.size()) 	
set<int> st;
map<int, int> mp;
const int mxn = 1e5;
void print(int n) { 
	cout << n << '\n';
}
void print(string s) {
	cout << s << '\n';
}
void print(vector<int> s) {
	for(auto x : s) cout << x << " ";
	cout << '\n';
}
template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}


int fomin(int a, int b, int c, int d) {
	return min(min(a, b), min(c, d));
}
int tmin(int a, int b, int c) {
	return min(min(a, b), c);
}
int fomax(int a, int b, int c, int d) {
	return max(max(a, b), max(c, d));
}
int tmax(int a, int b, int c) {
	return max(max(a, b), c);
}
void space() {
	cout << " ";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	read(t);
	while(t--) {
		ll a, b, c;
		read(a, b, c);
		cout << a+b+c-1 << '\n';
	}
	
}