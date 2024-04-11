#include<bits/stdc++.h>

using namespace std;

const int N=2005;
int n,Q,cnt[N],a[N][N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[0][i]);
	int t=0;
	for (;;){
		for (int i=1;i<=n;i++)
			cnt[i]=0;
		for (int i=1;i<=n;i++)
			++cnt[a[t][i]];
		for (int i=1;i<=n;i++)
			a[t+1][i]=cnt[a[t][i]];
		++t;
		bool flag=0;
		for (int i=1;i<=n;i++)
			if (a[t][i]!=a[t-1][i])
				flag=1;
		if (!flag) break;
	}
	scanf("%d",&Q);
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		y=min(y,t);
		printf("%d\n",a[y][x]);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}