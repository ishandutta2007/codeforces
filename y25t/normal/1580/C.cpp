#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define B 444

int n,m,a[N],b[N];

int lst[N];

int tot,bel[N],L[N],R[N];
inline void init(){
	for(int i=1;i<=m;i++){
		if(i%B==1)
			L[++tot]=i;
		R[tot]=i;
		bel[i]=tot;
	}
}
int sum[N],tag[N];
inline void add(int x,int d){
	sum[x]+=d,tag[bel[x]+1]+=d;
}
inline int qry(int x){
	int res=0;
	for(int i=x;i>=L[bel[x]];i--)
		res+=sum[i];
	for(int i=bel[x];i;i--)
		res+=tag[i];
	return res;
}

int s[B][B];
inline void chg(int x,ll t,int d){
	if(a[x]+b[x]<B){
		for(int i=a[x];i<a[x]+b[x];i++)
			s[a[x]+b[x]][(t+i)%(a[x]+b[x])]+=d;
	}
	else{
		while(t<=m){
			if(t+a[x]<=m)
				add(t+a[x],d);
			if(t+a[x]+b[x]<=m)
				add(t+a[x]+b[x],-d);
			t+=a[x]+b[x];
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=m;i++){
		int op,x;
		scanf("%d%d",&op,&x);
		if(op==1){
			chg(x,i,1);
			lst[x]=i;
		}
		else
			chg(x,lst[x],-1);
		int ans=qry(i);
		for(int j=1;j<B;j++)
			ans+=s[j][i%j];
		printf("%d\n",ans);
	}
}