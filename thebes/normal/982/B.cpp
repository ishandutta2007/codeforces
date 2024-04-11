#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
int N, i, x, y;
priority_queue<pii> a, b;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++){
		scanf("%d",&x);
		a.push({-x,i});
	}
	getchar();
	for(i=1;i<=2*N;i++){
		x = getchar()-'0';
		if(x){
			printf("%d ",b.top().second);
			b.pop();
		}
		else{
			printf("%d ",a.top().second);
			b.push({-a.top().first,a.top().second}); a.pop();
		}
	}
	return 0;
}