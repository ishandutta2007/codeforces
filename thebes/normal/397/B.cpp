#include <bits/stdc++.h>
using namespace std;

long long n, i, x, y, z, cnt;
int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(y>x){printf("No\n"); continue;}
		cnt = x/y;
		if((z-y)*cnt>=x-y*cnt) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}