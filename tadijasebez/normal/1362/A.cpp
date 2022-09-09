#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;scanf("%i",&t);
	while(t--){
		long long a,b;scanf("%lld %lld",&a,&b);
		int c=0,d=0;
		while(a%2==0)a/=2,c++;
		while(b%2==0)b/=2,d++;
		if(a==b)printf("%i\n",(abs(c-d)+2)/3);
		else printf("-1\n");
	}
	return 0;
}