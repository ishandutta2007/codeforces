#include <bits/stdc++.h>

int n,a,b,c;
int main() {
	int cnt=0;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		if(t==2) {
			if(b==0) cnt+=2;
			else b--;
		}
		else {
			if(a==0) {
				if(b==0) {
					if(c==0) cnt++;
					else c--;
				}
				else {
					b--;
					c++;
				}
			}
			else a--;
		}
	}
	printf("%d\n",cnt);
	return 0;
}