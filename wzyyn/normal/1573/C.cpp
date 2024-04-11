#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,f[N],q[N],ind[N];
vector<int> e[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		e[i].resize(0);
		ind[i]=0,f[i]=1;
	}
	int h=0,t=0;
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d",&x);
		if (!x) q[++t]=i;
		ind[i]=x;
		while (x--){
			int y;
			scanf("%d",&y);
			e[y].push_back(i);
		}
	}
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x]){
			f[i]=max(f[i],f[x]+(x>i));
			if (!--ind[i]) q[++t]=i;
		}
	}
	if (t!=n) puts("-1");
	else printf("%d\n",*max_element(f+1,f+n+1));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}