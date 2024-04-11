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
int a[300006]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	ll s = 0; 
	ll cnt = 0;
	ll sum = 0;  
	for (int i = n; i >= 1; --i) {
		sum += a[i]; 
		s += a[i] / 2; 
		if (a[i] % 2 == 1) 
			if (s > 0) s--; 
			else cnt++;  
	}
	cout<<(sum-cnt)/3<<endl; 
}