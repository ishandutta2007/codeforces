#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;
int n,p[maxn],a[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		int u;
		scanf("%d",&u);
		p[u]=i;
	}
	for (int i=1;i<=n;++i){
		int u;
		scanf("%d",&u);
		a[i]=p[u];
	//	printf("%d ",a[i]);
	}
	int ans=0,mn=n+1;
	for (int i=n;i>0;--i){
		if (a[i]>mn) ++ans;
		mn=min(a[i],mn);
	}
	printf("%d\n",ans);
	return 0;
}