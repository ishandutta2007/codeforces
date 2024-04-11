#include <bits/stdc++.h>
using namespace std;

int x, y, cnt, i, n, k;
char c;

int main(){
	for(scanf("%d",&n),getchar();i<n;i++){
		c = getchar();
		if(x == y){
			if(c == 'U' && k==1) cnt++;
			if(c == 'R' && k==2) cnt++;
			if(c == 'U') k=2;
			else k=1;
		}
		if(c == 'U') y++;
		else x++;
	}
	printf("%d\n",cnt);
	return 0;
}