#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;
int T,n;
int a[maxn],b[maxn],ida[maxn],idb[maxn],mna[maxn],mnb[maxn];
inline int cmpa(int x,int y){
	return a[x]<a[y];
}
inline int cmpb(int x,int y){
	return b[x]<b[y];
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),ida[i]=i;
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]),idb[i]=i;
		sort(ida+1,ida+1+n,cmpa),sort(idb,idb+1+n,cmpb);
		for(int i=1;i<=n;i++)
			a[ida[i]]=i,b[idb[i]]=i;
		mna[n+1]=mnb[n+1]=n+1;
		for(int i=n;i>=1;i--)
			mna[i]=min(mna[i+1],a[idb[i]]),mnb[i]=min(mnb[i+1],b[ida[i]]);
		int x=n,y=n;
		while(1){
			int u=mna[y],v=mnb[x];
			if(u==x&&v==y)
				break;
			x=u,y=v;
		}
		for(int i=1;i<=n;i++)
			printf("%d",(a[i]>=x||b[i]>=y));
		puts("");
	}
	return 0;
}