#include<bits/stdc++.h>
#define N 200005

int T;

int n,a[N];

int val[N],tot;

int c[N],mn[N],L[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),val[++tot]=a[i];
		std::sort(val+1,val+tot+1),tot=std::unique(val+1,val+tot+1)-val-1;
		for(int i=1;i<=tot;i++)
			c[i]=0,mn[i]=N;
		int ans=0,o,l,r;
		for(int i=1;i<=n;i++){
			int x=std::lower_bound(val+1,val+tot+1,a[i])-val;
			if(mn[x]>-(i-1)+2*c[x])
				mn[x]=-(i-1)+2*c[x],L[x]=i;
			c[x]++;
			if(ans<-i+2*c[x]-mn[x])
				ans=-i+2*c[x]-mn[x],o=val[x],l=L[x],r=i;
		}
		printf("%d %d %d\n",o,l,r);
	}
}