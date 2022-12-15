#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int N, M, i, j, x, y, sx, sy, p[4]={0,1,2,3}, ans;
string s[52], ins;

int main(){
	for(scanf("%d%d",&N,&M),i=0;i<N;i++){
		cin >> s[i];
		for(j=0;j<M;j++){
			if(s[i][j]=='S')
				sx=j,sy=i;
		}
	}
	cin >> ins;
	for(i=0;i<24;i++){
		x = sx; y = sy;
		for(char c : ins){
			int id = p[c-'0'];
			x += dx[id]; y += dy[id];
			if(y>=0&&y<N&&x>=0&&x<M&&s[y][x]!='#') x=x;
			else break;
			if(s[y][x] == 'E'){ans++; break;}
		}
		next_permutation(p, p+4);
	}
	printf("%d\n",ans);
	return 0;
}