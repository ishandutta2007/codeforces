#include<bits/stdc++.h>
using namespace std;

long long gcd (long long p, long long q){
	return q ? gcd(q, p % q) : p;
}

int a[100], b[100];

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	for(int i = 1; i <= n; i++)
		cin>>b[i];
	long long x = 1;
	for(int i = 1; i <= n; i++)
		x = x * a[i] / gcd(x, a[i]);
	int cnt = 0;
	for(int i = 1; i <= x; i++){
		int flag = 0;
		for(int j = 1; j <= n; j++)
			if (i % a[j] == b[j]){
				flag = 1;
				break;
			}
		cnt += flag;
	}
	printf("%.10f\n", cnt * 1.0 / x);
	return 0;
}