#include"bits/stdc++.h"
#define skip { puts("NO"); return 0;}
using namespace std;
int n,a,p;char opt[20];
int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; i++){
		scanf ("%d %s",&a,opt);
		if (opt[0]=='N') {
			if (p-a<0) skip;
			p-=a;
		} else if (opt[0]=='S'){
			if (p+a>20000) skip;
			p+=a;
		} else if (p==0||p==20000) skip;
	}
	puts(p==0?"YES":"NO");
	return 0;
}