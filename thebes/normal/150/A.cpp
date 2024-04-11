#include <bits/stdc++.h>
using namespace std;

long long n, i, cnt, f=1LL<<60, s = 1LL<<60;
void check(){
	long long r = n;
	for(i=2;i<=sqrt(n+0.0);i++){
		while(r%i==0){
			cnt++; 
			if(i < f){s=f; f=i;}
			else if(i < s) s=i;
			r /= i;
		}
	}
	if(r != 1){
		if(r < f) s=f,f=r;
		else if(r < s) s=r;
		cnt++;
	}
}

int main(){
	scanf("%lld",&n);
	check();
	if(cnt == 1) printf("1\n0\n");
	else if(cnt==2) printf("2\n");
	else printf("1\n%lld\n",f*s);
	return 0;
}