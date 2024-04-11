#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
using vl = vector<ll>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

const int maxn = 3000006; 

char s[maxn]; 
ll ans; 

int main() {
	ans = 0; 
	scanf( "%s", s+1 ); 
	int n = strlen(s+1); 
	int k = n+1; 
	ans = 0; 
	for (int i = n; i >= 1; --i) {
		for (int j = 1; i+j*2 <= k; ++j) 
			if (i+j*2 <= n && s[i+j] == s[i] && s[i+j*2] == s[i]) {
				k = i+j*2; 
				break; 
			}
		ans += max(0,n-k+1); 
	}
	cout<<ans<<endl; 
		
}