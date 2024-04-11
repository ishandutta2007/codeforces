#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;
typedef long long lli;

int n=9;
char str[9][10];
int main() {
	char tmp;
	for(int i=0;i<n;i++) {
		if(i!=0 && i%3==0) scanf("%c",&tmp);
		for(int j=0;j<n;j++) {
			if(j!=0 && j%3==0) scanf("%c",&tmp);
			scanf("%c",&str[i][j]);
		}
		scanf("%c",&tmp);
	}
	int y,x;
	scanf("%d%d",&y,&x);

	int flag=0;
	for(int i=(y-1)%3*3;i<(y-1)%3*3+3;i++) {
		for(int j=(x-1)%3*3;j<(x-1)%3*3+3;j++) {
			if(str[i][j]=='.') {
				flag=1;
				str[i][j]='!';
			}
		}
	}
	if(!flag) {
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(str[i][j]=='.') {
			str[i][j]='!';
		}
	}
	for(int i=0;i<n;i++) {
		if(i!=0 && i%3==0) puts("");
		for(int j=0;j<n;j++) {
			if(j!=0 && j%3==0) printf(" ");
			printf("%c",str[i][j]);
		}
		puts("");
	}
	return 0;
}