#include<bits/stdc++.h>
using namespace std;

const int maxn=1000007;
int a[maxn],s[maxn];
int main(){
	int n;
	scanf("%d",&n);
	s[0]=0;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",(s[v]-s[u-1])/10);
	}
	return 0;
}