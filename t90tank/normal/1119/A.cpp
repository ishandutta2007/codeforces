#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

int n; 
int c[300006]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &c[i] ); 
	int ans = 0; 
	for (int i = n; i >= 2; --i) 
		if (c[i] != c[1]) {ans = i-1; break;}
	for (int i = 1; i < n; ++i) 
		if (c[i] != c[n]) {ans = max(ans,n-i); break;}
	cout<<ans<<endl; 
}