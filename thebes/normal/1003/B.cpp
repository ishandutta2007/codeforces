#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
int main(){
	scanf("%d%d%d",&a,&b,&d);
	printf("%c",(a>=b)?'0':'1');
	if(a >= b){a--; c=0;}
	else{b--; c=1;}
	while(a||b){
		if(a&&b){
			if(c==0){
				if(d>1){
					d--; b--; c = 1;
					printf("1");
				}
				else a--, printf("0");
			}
			else{
				if(d>1){
					d--; a--; c = 0;
					printf("0");
				}
				else b--, printf("1");
			}
		}
		else if(a) printf("0"),a--;
		else printf("1"),b--;
	}
	return 0;
}