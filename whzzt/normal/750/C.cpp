#include"bits/stdc++.h"
#define skip { puts("Impossible"); return 0;}
using namespace std;
const int N=200005;
int n,c[N],d[N];
long long l,r,now;
int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d%d",&c[i],&d[i]);
	l=-0x7fffffff; r=0x7fffffff;
	for (int i=n; i>=1; i--){
		r-=c[i]; l-=c[i];
		if (d[i]==1) l=max(l,1900ll);
		else r=min(r,1899ll);
		if (l>r) skip;
	}
	if (r>200000000) puts("Infinity");
	else { now=r;
		for (int i=1; i<=n; i++)
			now+=c[i];
		cout<<now<<endl;
	}
	return 0;
}