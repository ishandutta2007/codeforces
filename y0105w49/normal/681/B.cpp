#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	for(int a=0;a<=n;a+=1234567) for(int b=0;b+a<=n;b+=123456) {
		int c=(n-a-b)/1234*1234;
		assert(c>=0);
		if(a+b+c==n) return cout<<"YES\n",0;
	}
	cout<<"NO\n";
}