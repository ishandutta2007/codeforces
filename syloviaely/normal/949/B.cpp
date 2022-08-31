#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
long long n;
int q;
long long solve(long long k){
	//cout<<"asd "<<k<<endl; int kk; cin>>kk;
	if (k&1) return (k+1)/2;
	long long pre=k/2;
	long long rem=n-pre-1;
	return solve(k+rem+1);
}
int main(){
	scanf("%I64d %d",&n,&q);
	for (;q;q--){
		long long k; scanf("%I64d",&k);
		printf("%I64d\n",solve(k));
	}
	return 0;
}