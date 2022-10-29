#include <cstdio>
#include <algorithm>
#include <cstring>
char s[2][25];
int n,count[2][105];
bool p[2][105];
char team[3],y[3];
int main() {
	scanf("%s",s[0]);
	scanf("%s",s[1]);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		int t,te,no,x; 
		scanf("%d%s%d%s",&t,team,&no,y);
		if (team[0] == 'h') te = 0;
		else te = 1;
		if (y[0] == 'y') x = 1;
		else x = 2;
		count[te][no] += x;
		if (count[te][no] >= 2 && !p[te][no]) {
			printf("%s %d %d\n",s[te],no,t);
			p[te][no] = true;
		}
	}
}