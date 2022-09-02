// author: xay5421
// created: Sun Sep 12 22:36:42 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		int n,s;
		scanf("%d%d",&n,&s);
		int tmp=n-(n+1)/2+1;
		printf("%d\n",s/tmp);
	}
	return 0;
}