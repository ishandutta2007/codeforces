#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 5006; 

char s[maxn]; 
int n; 
int a[30][maxn][30];  

int main() {
	scanf( "%s", s ); 
	n = strlen(s); 
	for (int i = 0; i < n; ++i) {
		int x = s[i]-'a'; 
		for (int j = 1; j < n; ++j) 
			a[x][j][s[(i+j)%n]-'a']++; 
	}
	int ans = 0; 
	for (int i = 0; i < 26; ++i) {
		int d = 0; 
		for (int j = 1; j < n; ++j) {
			int t = 0; 
			for (int k = 0; k < 26; ++k) 
				if (a[i][j][k] == 1) t++; 
			d = max(d, t); 
		}
		ans += d; 
	}
	printf( "%.12f\n", db(ans)/n ); 
}