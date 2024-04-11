#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int n;
	scanf("%i",&n);
	vector<int> a(n);
	for(int&i:a)scanf("%i",&i);
	vector<int> primes;
	const int S=3200;
	vector<bool> sieve(S,false);
	for(int i=2;i<S;i++){
		if(!sieve[i]){
			primes.pb(i);
			for(int j=i*2;j<S;j+=i)sieve[j]=true;
		}
	}
	vector<int> x,y;
	for(int k:a){
		int pr=k;
		for(int p:primes){
			if(p*p>k)break;
			if(k%p==0){
				pr=p;
				break;
			}
		}
		int X=1,Y;
		while(k%pr==0){
			X*=pr;
			k/=pr;
		}
		Y=k;
		if(X==1||Y==1)x.pb(-1),y.pb(-1);
		else x.pb(X),y.pb(Y);
	}
	for(int i:x)printf("%i ",i);printf("\n");
	for(int i:y)printf("%i ",i);printf("\n");
	return 0;
}