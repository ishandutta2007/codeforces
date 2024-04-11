#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int p[N],q[N],pl[N],ql[N],dst[N];
int ans[N];
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	for(int i=1;i<=n;i++)scanf("%i",&p[i]),ql[p[i]]=i;
	for(int i=1;i<=n;i++)scanf("%i",&q[i]),pl[q[i]]=i;
	for(int i=n;i>=1;i--){
		dst[i]=i;
		if(pl[p[i]]!=1)
			dst[i]=max(dst[i],ql[q[pl[p[i]]-1]]);
	}
	for(int i=2;i<=n;i++)dst[i]=max(dst[i],dst[i-1]);
	int j=26;
	for(int i=n;i>=1;i--){
		if(dst[i]==i)j=max(j-1,0);
		ans[p[i]]=j;
	}
	if(26-j<k)printf("NO\n");
	else{
		printf("YES\n");
		for(int i=1;i<=n;i++)printf("%c",'a'+ans[i]);
	}
	return 0;
}