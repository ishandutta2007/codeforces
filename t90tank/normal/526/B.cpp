#include <bits/stdc++.h>
using namespace std; 

int n, m; 
int a[1000000]; 
int b[1000000]; 

int main() {
	cin>>n;
	int m = (1<<(n+1))-1;  
	for (int i = 2; i <= m; ++i) cin>>a[i];
	for (int i = m; i >= 1; --i) b[i] = max( b[i*2]+a[i*2], b[i*2+1]+a[i*2+1] ); 
	int sum = 0; 
	for (int i = 1; i <= m/2; ++i) {
		int t = (b[i*2]+a[i*2])-(b[i*2+1]+a[i*2+1]); 
		sum += max( t, -t ); 
	}  
	cout<<sum<<endl; 
}