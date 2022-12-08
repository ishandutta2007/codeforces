#include <bits/stdc++.h>
using namespace std; 

using ll = long long; 
#define fir first
#define sec second 
#define pb push_back
using vi = vector<int>; 

const int maxn = 300006; 

int n;
set<int> e[30];  
char s[200000]; 
bool need[30], v[30]; 
int ans[30], tot; 
int ind[30], a[30]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) {
		scanf( "%s", s ); 
		int len = strlen(s); 
		for (int j = 0; j < len; ++j) 
			need[s[j]-'a'] = true; 
		for (int j = 0; j < len-1; ++j) {
			e[s[j]-'a'].insert(s[j+1]-'a'); 
			ind[s[j+1]-'a']++; 
		}
		memset(a, 0, sizeof(a)); 
		for (int j = 0; j < len; ++j) a[s[j]-'a']++; 
		for (int j = 0; j < 30; ++j) 
			if (a[j] > 1) {
				puts( "NO" ); 
				return 0; 
			}
	}
	memset(v, false, sizeof(v)); 
	tot = 0; 
	for (int i = 0; i < 26; ++i)
		if (ind[i] == 0 && need[i] && !v[i]) {
			int x = i; 
			ans[++tot] = i; 
			v[x] = true; 
			while (e[x].size() != 0) {
				if (e[x].size() > 1) {
					puts( "NO" ); 
					return 0; 
				}
				x = *e[x].begin(); 
				ans[++tot] = x; 
				if (v[x]) {
					puts( "NO" ); 
					return 0;
				}
				v[x] = true; 
			} 
		}
	for (int i = 0; i < 26; ++i)
		if (need[i] && !v[i]) {
			puts( "NO" ); 
			return 0;
		}
	for (int i = 1; i <= tot; ++i) 
		printf( "%c", ans[i] + 'a' ); 
	puts( "" ); 
}