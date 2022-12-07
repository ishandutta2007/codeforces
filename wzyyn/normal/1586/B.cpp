#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n,m,vi[100005];
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) vi[i]=0;
	for (int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		vi[y]=1;
	}
	int p=1;
	for (;vi[p];++p);
	for (int i=1;i<=n;i++)
		if (i!=p) printf("%d %d\n",p,i);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}