#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int arr[MN][30], N, M, i, x, y, w, p, s;
tuple<int,int,int> q[MN];

int qu(int x, int y){
	int r = 0, p = 29;
	for(;p>=0;p--){
		if(arr[y][p]-arr[x-1][p]==y-x+1)
			r += (1<<p);
	}
	return r;
}

int main(){
	for(scanf("%d%d",&N,&M);i<M;i++){
		scanf("%d%d%d",&x,&y,&w);
		q[i] = {x,y,w};
		for(p=29;p>=0;p--){
			if((1<<p)&w)
				arr[x][p]++,arr[y+1][p]--;
		}
	}
	for(p=29;p>=0;p--){
		for(i=1;i<=N+1;i++){
			s += arr[i][p];
			arr[i][p]=arr[i-1][p];
			arr[i][p]+=(s)?1:0;
		}
	}
	bool flag = false;
	for(i=0;i<M;i++){
		x=get<0>(q[i]),y=get<1>(q[i]);
		if(qu(x,y)!=get<2>(q[i]))
			flag = 1;
	}
	if(flag) printf("NO\n");
	else{
		printf("YES\n");
		for(i=1;i<=N;i++){
			int cur = 0;
			for(p=29;p>=0;p--){
				if(arr[i][p]-arr[i-1][p])
					cur += (1<<p);
			}
			printf("%d ",cur);
		}
	}
	return 0;
}