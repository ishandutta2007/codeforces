#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;scanf("%i",&t);
	while(t--){
		int a,b,c,d;scanf("%i %i %i %i",&a,&b,&c,&d);
		if(a>b)swap(a,b);if(c>d)swap(c,d);
		if(b==d&&a+c==b)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}