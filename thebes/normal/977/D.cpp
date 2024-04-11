#include <bits/stdc++.h>
using namespace std;

struct pii{long long f, s, val;}arr[101];
int n, i; long long x;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%lld",&x); arr[i].val=x;
		while(x%2==0){x/=2; arr[i].s++;}
		while(x%3==0){x/=3; arr[i].f++;}
	}
	sort(arr+1,arr+n+1,[](pii i,pii j){
		if(i.f==j.f) return i.s<j.s;
		else return i.f>j.f;
	});
	for(i=1;i<=n;i++) 
		printf("%lld ",arr[i].val);
	return 0;
}