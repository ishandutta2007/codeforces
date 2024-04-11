#include<bits/stdc++.h>
#define first F
#define second S
using namespace std;

long long n,k,t;

int ct(long long u){
	int ans=0;
	while (u){
		if (u&1) ans++;
		u>>=1;
	}
	return ans;
}
int main(){
	cin>>n>>k;
	int i=1; 
	while (1){
		if ((k+1)*i>n){
			printf("-1");
			return 0;
		}
		t=n-k*i;
		int v=ct(t);
		if (v<=i){
			printf("%d",i);
			return 0;
		} 
		i++;
	}
	return 0;
}