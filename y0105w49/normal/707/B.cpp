#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	const int N=1.1e5;
	static int u[N],v[N],l[N];
	static bool bad[N];
	for(int i=0;i<m;i++) scanf("%d%d%d",u+i,v+i,l+i), --u[i], --v[i];
	for(int a;k--;) scanf("%d",&a), bad[a-1]=1;
	int we=1e9+99;
	for(int i=0;i<m;i++) if(l[i]<we && bad[u[i]]+bad[v[i]]==1) we=l[i];
	printf("%d\n",we>1e9?-1:we);
}