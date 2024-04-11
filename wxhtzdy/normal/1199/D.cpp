#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int n,q,a[N],op[N],p[N],x[N],suff[N],lst[N];
int main(){
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	scanf("%i",&q);
	for(int i=1;i<=q;i++){
		scanf("%i",&op[i]);
		if(op[i]==1)scanf("%i%i",&p[i],&x[i]);
		else scanf("%i",&x[i]);
	}
	for(int i=q;i>=1;i--){
		if(op[i]==1)suff[i]=suff[i+1],lst[p[i]]=max(lst[p[i]],i);
		else suff[i]=max(suff[i+1],x[i]);
	}
	for(int i=1;i<=n;i++){
		if(!lst[i])printf("%i ",max(a[i],suff[1]));
		else printf("%i ",max(suff[lst[i]],x[lst[i]]));
	}
}