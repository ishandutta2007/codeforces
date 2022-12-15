#include <bits/stdc++.h>
using namespace std;

int n, i, x, y, a;
int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(x>y) a++;
		if(y>x) a--;
	}
	printf("%s\n",(a)?(a>0)?"Mishka":"Chris":"Friendship is magic!^^");
	return 0;
}