#include <bits/stdc++.h>
using namespace std;

long long n, m, i, x, tot, d;
int main(){
	scanf("%lld%lld",&n,&tot);
	for(i=1;i<=n;i++){
		char ch; cin >> ch >> x;
		if(ch=='+') tot += x;
		else if(ch=='-'){
			if(tot>=x) tot-=x;
			else d++;
		}
	}
	printf("%lld %lld\n",tot,d);
	return 0;
}