#include <bits/stdc++.h>
using namespace std; 

const int maxn = 200000; 

int n; 
int a[maxn]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) {
		int s; 
		scanf( "%d", &s ); 
		for (int j = 1; j*j <= s; ++j) 
			if (s % j == 0) {
				a[j]++; 
				if (s/j != j) a[s/j]++; 
			} 
	}
	int ans = 1; 
	for (int i = 2; i < maxn; ++i) {
		//cout<<a[i]<<endl; 
		ans = max(ans, a[i]); 
	}
	cout<<ans<<endl; 
}