#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <cstring>

using namespace std;

const int dy[4]={-1,1,0,0},dx[4]={0,0,-1,1};
int di[4];

int n,m;
char str[101][101],is[101];

int vis[51][51];

int sy,sx,fy,fx,len,res;

void check() {
	int y=sy,x=sx;
	for(int i=0;i<len;i++) {
		y+=dy[di[is[i]]]; x+=dx[di[is[i]]];
		if(y<0 || x<0 || y>=n || x>=m || str[y][x]=='#'){
			return;
		}
		if(y==fy && x==fx) {
			res++;
			break;
		}
	}
}
void f(int idx,int s) {
	if(idx==4) {
		check();
		return;
	}
	for(int i=0;i<4;i++) {
		if(!(s&(1<<i))) {
			di[idx]=i;
			f(idx+1,s|(1<<i));
		}
	}
}

int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%s",str[i]);
		for(int j=0;j<m;j++) {
			if(str[i][j]=='S') {
				sy=i; sx=j;
			}
			else if(str[i][j]=='E') {
				fy=i; fx=j;
			}

		}
	}
	scanf("%s",is);
	len=strlen(is);
	for(int i=0;i<len;i++) is[i]-='0';
	f(0,0);
	printf("%d\n",res);
	return 0;
}