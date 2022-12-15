#include <bits/stdc++.h>
using namespace std;

int n, a, b, x, i;

int main(){
	for(i=0;i<3;i++){
		scanf("%d",&x);
		a += x;
	}
	for(i=0;i<3;i++){
		scanf("%d",&x);
		b += x;
	}
	scanf("%d",&n);
	if(ceil((double)a/5)+ceil((double)b/10)<=n) printf("YES\n");
	else printf("NO\n");
	return 0;
}