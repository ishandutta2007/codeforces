#include <bits/stdc++.h>
using namespace std;

int tot, mx, n, s, i, x;
int main(){
	for(scanf("%d%d",&n,&s),i=1;i<=n;i++){
		scanf("%d",&x); tot+=x;
		mx=max(mx, x);
	}
	printf("%s\n",(tot-mx<=s)?"YES":"NO");
	return 0;
}