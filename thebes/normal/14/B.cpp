#include <bits/stdc++.h>
using namespace std;

int N, P, i, x, y, a=-1, b;

int main(){
	for(scanf("%d%d",&N,&P),i=0;i<N;i++){
		scanf("%d%d",&x,&y);
		if(x > y) swap(x,y);
		if(a==-1){a=x; b=y;}
		else{a=max(x,a); b=min(y,b);}
	}
	if(a > b) printf("-1\n");
	else if(a<=P&&P<=b) printf("0\n");
	else if(P<a) printf("%d\n",a-P);
	else printf("%d\n",P-b);
	return 0;
}