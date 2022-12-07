#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int d[100005];
priority_queue<pair<int,int> > Q;
void solve(){
	scanf("%d%d%d",&n,&m,&x);
	for (;!Q.empty();Q.pop());
	for (int i=1;i<=m;i++){
		d[i]=0;
		Q.push(pair<int,int>(d[i],i));
	}
	puts("YES");
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		int y=Q.top().second;
		Q.pop();
		d[y]-=x;
		printf("%d ",y);
		Q.push(pair<int,int>(d[y],y));
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}