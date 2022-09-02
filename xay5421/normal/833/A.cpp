#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
int n;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int a,b;
		scanf("%d%d",&a,&b);
		LL t=1LL*a*b;
		LL c=pow(t,1./3);
		while(c*c*c<t)++c;
		while(c*c*c>t)--c;
		if(c*c*c==t&&a%c==0&&b%c==0){
			puts("Yes");
		}else{
			puts("No");
		}
	}
	return 0;
}