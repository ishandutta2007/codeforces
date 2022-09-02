#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
int n,p;
int main(){
	scanf("%d%d",&n,&p);
	rep(i,1,60){
		n-=p;
		if(n>=0&&__builtin_popcountll(n)<=i&&i<=n){
			printf("%d\n",i);
			exit(0);
		}
	}
	puts("-1");
	return 0;
}