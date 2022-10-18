#include<bits/stdc++.h>
#define N 1000005

int n,m,q,a[N];
char s[N];

#define num(x,y) (((x)-1)*m+(y))

int f[N],g[N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			a[num(i,j)]=s[j]=='X';
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(i==1||j==1)
				f[num(i,j)]=1;
			else{
				f[num(i,j)]=j;
				if(!a[num(i-1,j)])
					f[num(i,j)]=std::min(f[num(i,j)],f[num(i-1,j)]);
				if(!a[num(i,j-1)])
					f[num(i,j)]=std::min(f[num(i,j)],f[num(i,j-1)]);
			}
			g[j]=std::max(g[j],f[num(i,j)]);
		}
	for(int i=1;i<=m;i++)
		g[i]=std::max(g[i],g[i-1]);
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		puts(g[r]<=l?"YES":"NO");
	}
}