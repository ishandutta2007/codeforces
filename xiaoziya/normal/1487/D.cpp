#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,tot;
int a[maxn],q[maxn],id[maxn],ans[maxn];
inline int cmp(int a,int b){
	return q[a]<q[b];
}
int main(){
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
		scanf("%d",&q[i]),id[i]=i;
	sort(id+1,id+1+T,cmp);
	int j=1;
	for(int i=3;;i+=2){
		int a=i,b=(i*i-1)/2,c=b+1;
		if(b>1e9||c>1e9)
			break;
		while(j<=T&&(q[id[j]]<a||q[id[j]]<b||q[id[j]]<c))
			ans[id[j]]=tot,j++;
		tot++;
	}
	while(j<=T)
		ans[id[j]]=tot,j++;
	for(int i=1;i<=T;i++)
		printf("%d\n",ans[i]);
	return 0;
}