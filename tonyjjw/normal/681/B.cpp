#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MN = 100000 + 1;

ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(){
	ll N;
	scanf("%lld",&N);
	ll a=1234567, b=123456, c=1234;
	ll ans=0;
	for(ll k1=0;a*k1<=N;k1++){
		for(ll k2=0;a*k1+b*k2<=N;k2++){
			if((N-a*k1-b*k2)%c==0){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}