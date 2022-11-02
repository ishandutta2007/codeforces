#include<bits/stdc++.h>
using namespace std;
int n,m,a[200009],f[200009];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==a[i-1]) f[i]=f[i-1];
		else f[i]=i;
	}
	for(int i=1;i<=m;i++){
		int l,r,x;scanf("%d%d%d",&l,&r,&x);
		if(a[r]!=x) printf("%d\n",r);
		else if(f[r]<=l) printf("-1\n");
		else printf("%d\n",f[r]-1);
	}
	return 0;
}