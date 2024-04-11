#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int state[N][2],bal;
int Get(int i){
	if(!state[i][0] && !state[i+1][0])return 0;
	if(!state[i][1] && !state[i+1][1])return 0;
	return 1;
}
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	while(m--){
		int x,y;
		scanf("%i %i",&x,&y);
		x--;
		bal-=Get(y);
		bal-=Get(y-1);
		state[y][x]^=1;
		bal+=Get(y);
		bal+=Get(y-1);
		if(bal)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}