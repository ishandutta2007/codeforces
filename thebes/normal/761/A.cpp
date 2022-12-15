#include <bits/stdc++.h>
using namespace std;

int x, y;
int main(){
	scanf("%d%d",&x,&y);
	if(x==y&&x==0) printf("NO\n");
	else if(abs(x-y)<=1) printf("YES\n");
	else printf("NO\n");
	return 0;
}