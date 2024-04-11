#include <bits/stdc++.h>

int n,m;
char str[101][101];

int main() {
	scanf("%d%d",&n,&m);
	int x1=m,x2=-1,y1=n,y2=-1,cnt=0;
	for(int i=0;i<n;i++) {
		scanf("%s",str[i]);
		for(int j=0;j<m;j++) {
			if(str[i][j]=='B') {
				x1=std::min(x1,j);
				x2=std::max(x2,j);
				y1=std::min(y1,i);
				y2=std::max(y2,i);
				cnt++;
			}
		}
	}
	if(cnt==0) {
		printf("1\n");
		return 0;
	}
	int dif=(y2-y1+1)-(x2-x1+1);
	if(dif==0) printf("%d\n",(y2-y1+1)*(y2-y1+1)-cnt);
	else {
		if(dif<0) {
			if((x2-x1+1)>n) {
				printf("-1\n");
			}
			else {
				printf("%d\n",(x2-x1+1)*(x2-x1+1)-cnt);
			}
		}
		else {
			if((y2-y1+1)>m) {
				printf("-1\n");
			}
			else {
				printf("%d\n",(y2-y1+1)*(y2-y1+1)-cnt);
			}
		}
	}
	return 0;
}