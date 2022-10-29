#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const int MOD = 998244353;
const int N = 100010;

LL a[N],x,n=0;

LL calc(LL x, LL i){
	return (x-i+2)*x/i/2; 
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>x;
	for(int i=1;i*i<=x;++i)if(x%i==0){
		a[++n] = calc(x,i);
		if(i*i<x)a[++n] = calc(x,x/i);
	}
	sort(a+1,a+n+1);
	rep(i,1,n)cout<<a[i]<<" ";
	return 0;
}