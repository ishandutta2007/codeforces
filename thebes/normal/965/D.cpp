#include <bits/stdc++.h>
using namespace std;
struct idk{int mx, p;idk(int a,int b):mx(a),p(b){};};
queue<idk> q; int N, L, i, cnt, x, y, cap;
int main(){
	q.push(idk(1<<30,0));
	for(scanf("%d%d",&N,&L),i=1;i<N;i++){
		scanf("%d",&x); cap = 0;
		while(q.size()&&x){
			if(q.front().p+L<i){q.pop();continue;}
			int lol = min(q.front().mx,x);
			cap += lol; x-=lol; q.front().mx-=lol;
			if(q.front().mx==0) q.pop();
		}
		q.push(idk(cap,i));
	}
	x = 1<<30; cap = 0;
	while(q.size()&&x){
		if(q.front().p+L<i){q.pop();continue;}
		int lol = min(q.front().mx,x);
		cap += lol; x-=lol; q.front().mx-=lol;
		if(q.front().mx==0) q.pop();
	}
	printf("%d\n",cap);
	return 0;
}