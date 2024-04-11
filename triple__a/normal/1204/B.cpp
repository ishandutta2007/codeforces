#include<bits/stdc++.h>
using namespace std;

long long n,l,r;

long long power(long long x,long long y){
	long long ans=1;
	for (int i=1;i<=y;++i){
		ans*=x;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>l>>r;
	cout<<power(2,l)+n-l-1<<" "<<power(2,r)-1+(n-r)*power(2,r-1);
	return 0;
}