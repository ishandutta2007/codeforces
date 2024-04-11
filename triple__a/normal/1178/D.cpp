#include<bits/stdc++.h>

using namespace std;

bool prime_test(int n){
	int q=sqrt(n);
	for (int i=2;i<=q;++i){
		if (n%i) continue;
		return 0;
	}
	return 1;
}

int sh(int n){
	int u=n*3/2;
	for (int i=n;i<=u;++i){
		if (prime_test(i)) return i;
	}
	return -1;
}
int n;
int main(){
	scanf("%d",&n);
	int u=sh(n);
	printf("%d\n",u);
	for (int i=0;i<n;++i){
		printf("%d %d\n",i+1,(i+1)%n+1);
	}
	int l=1;
	while (u>n){
		if (l%4==3) l+=2;
		printf("%d %d\n",l,l+2);
		l++,u--;
	}
	return 0;
}