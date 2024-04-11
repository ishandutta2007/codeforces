using namespace std;
#include<bits/stdc++.h>
int main() {
	int n;
	cin>>n;
	if(n % 2==0) {
		puts("-1");
		return 0;
	}
	for(int i = 0; i <= n - 1; i ++) {
		cout<<i<<" ";
	}
	puts("");
	for(int j = 0;j <= n - 1; j ++) {
		cout<<j<<" ";
	}
	puts("");
	for(int i = 0 ;i < n ;i ++) {
		cout<<(i*2) %n<<" ";
	}
}