#include <bits/stdc++.h>
using namespace std;

pair<int,int> p;
int id, N, i, a, b, c, d, s = 1<<30;

int main(){
	for(scanf("%d",&N),i=0;i<4;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int x = min(a,b)+min(c,d);
		if(x < s){
			id = i; s = x;
			p = make_pair(min(a,b),min(c,d));
		}
	}
	if(s <= N){
		printf("%d %d %d\n",id+1,p.first,N-p.first);
	}
	else printf("-1");
	return 0;
}