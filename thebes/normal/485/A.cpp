#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int x, y;
bitset<MN> vis;

int main(){
	scanf("%d%d",&x,&y);
	while(!vis[x]&&x){
		vis[x] = 1;
		x = (2*x)%y;
	}
	printf("%s\n",(!x)?"Yes":"No");
	return 0;
}