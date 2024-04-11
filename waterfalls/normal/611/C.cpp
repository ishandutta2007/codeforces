#include <bits/stdc++.h>
using namespace std;

int h,w,q;
char grid[513][513];
int sum[513][513];

int main() {
	scanf("%d%d",&h,&w);
	for (int i=0;i<h;i++) scanf(" %s",&grid[i]);
	for (int i=0;i<h;i++) for (int j=0;j<w;j++) {
		if (grid[i][j]=='.' && grid[i][j+1]=='.') sum[i][j]+=1;
		if (grid[i][j]=='.' && grid[i+1][j]=='.') sum[i][j]+=1;
	}
	for (int i=0;i<h;i++) for (int j=0;j<w;j++) {
		if (i) sum[i][j]+=sum[i-1][j];
		if (j) sum[i][j]+=sum[i][j-1];
		if (i && j) sum[i][j]-=sum[i-1][j-1];
	}
	scanf("%d",&q);
	for (int i=0;i<q;i++) {
		int r1,c1,r2,c2;
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		r1-=1; c1-=1; r2-=1; c2-=1;
		int ans = 0;
		if (r2>r1 && c2>c1) {
			ans+=sum[r2-1][c2-1];
			if (r1) ans-=sum[r1-1][c2-1];
			if (c1) ans-=sum[r2-1][c1-1];
			if (r1 && c1) ans+=sum[r1-1][c1-1];
		}
		for (int j=c1;j<c2;j++) {
			if (grid[r2][j]=='.' && grid[r2][j+1]=='.') ans+=1;
		}
		for (int j=r1;j<r2;j++) {
			if (grid[j][c2]=='.' && grid[j+1][c2]=='.') ans+=1;
		}
		printf("%d\n",ans);
	}

	return 0;
}