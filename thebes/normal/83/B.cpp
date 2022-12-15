#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 1e5+5;
ll arr[MN], N, K, lo, hi, i, x, k[MN];
queue<ll> q;

int main(){
	for(scanf("%lld%lld",&N,&K),i=1;i<=N;i++)
		scanf("%lld",&arr[i]),x+=arr[i];
	if(x < K) printf("-1\n");
	else if(x == K) printf(" ");
	else{
		lo = 0; hi = 1e9+1e5;
		while(lo < hi){
			ll t=0, m=(lo+hi)/2;
			for(i=1;i<=N;i++)
				t += min(arr[i],m);
			if(t > K) hi=m;
			else lo=m+1;
		}
		lo--; ll t = 0; 
		for(i=1;i<=N;i++){
			t += min(arr[i],lo);
			if(lo >= arr[i]) k[i]=1;
			else arr[i] -= lo;
		}
		for(i=1;t<K;i++){
			if(!k[i]){
				t++; if((--arr[i])==0) k[i]=1;
			}
		}
		if(!k[i]){printf("%lld ",i);} ll j=i;
		for(i=(i==N)?1:i+1;i!=j;i=(i==N)?1:i+1)
			if(!k[i]) printf("%lld ",i);
	}
	return 0;
}