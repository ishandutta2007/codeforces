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

const int maxn = 300006; 

int n, m; 
int a[maxn];
int f[maxn];  

int main() {
	scanf("%d%d", &n, &m); 
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]); 
	a[0] = 0; 
	int l = -1, r = m-1; 
	while (l+1 < r) {
		int mid = (l+r) / 2; 
		f[0] = 0;
		bool flag = true;  
		for (int i = 1; i <= n; ++i) 
			if (a[i]<=f[i-1] && f[i-1]<=a[i]+mid)
				f[i] = f[i-1]; 
			else if (a[i]+mid >= m && a[i]+mid-m >= f[i-1])
				f[i] = f[i-1]; 
			else if (a[i]+mid < f[i-1]) {
				flag = false;
				break; 
			}
			else f[i] = a[i]; 
		if (flag) r = mid; 
		else l = mid; 
	}   
	printf( "%d\n", r ); 
}