#include<bits/stdc++.h>
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
int T;
int main(){
	rd(T);
	while(T--){
		int p1,p2,k;rd(p1),rd(p2),rd(k);
		if(p1>p2)swap(p1,p2);
		int g=__gcd(p1,p2);
		p1/=g,p2/=g;
		int now=max(0,(p2-2)/p1)+1;
		if(now<k)puts("OBEY");
		else puts("REBEL");
	}
	return 0; 
}