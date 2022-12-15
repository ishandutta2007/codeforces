#include <bits/stdc++.h>
using namespace std;

int a, b, w, n;

int main(){
	scanf("%d%d%d%d",&a,&b,&w,&n);
	if(a+b-w>=n) printf("-1\n");
	else if(w>a||w>b) printf("-1\n");
	else if(w>=n||a>=n||b>=n) printf("-1\n");
	else if(n==0) printf("-1\n");
	else printf("%d\n",n-(a+b-w));
	getchar(); getchar();
}