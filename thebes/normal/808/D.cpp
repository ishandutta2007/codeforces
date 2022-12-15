#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 1e5+5;
ll p[MN], N, arr[MN], i, x, tot, a;
multiset<ll> s, t;

int main(){
	for(scanf("%lld",&N),i=1;i<=N;i++)
		scanf("%lld",&arr[i]),tot+=arr[i],t.insert(arr[i]);
	for(i=1;i<=N;i++){
		s.insert(arr[i]); t.erase(t.find(arr[i])); x += arr[i]; 
		if(x == tot-x){a=1; break;}
		else if(x > tot-x && (2*x-tot)%2==0){
			if(s.find((2*x-tot)/2)!=s.end()){a=1; break;}
		}
		else if(x < tot-x && (tot-2*x)%2==0){
			if(t.find((tot-2*x)/2)!=t.end()){a=1; break;}
		}
	}
	printf("%s\n",(a)?"YES":"NO");
	return 0;
}