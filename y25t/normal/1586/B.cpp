#include<bits/stdc++.h>
#define N 300005

int T;

int n,m,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			a[i]=0;
		for(int i=1;i<=m;i++){
			int x;
			scanf("%*d%d%*d",&x);
			a[x]=1;
		}
		for(int i=1;i<=n;i++)
			if(!a[i]){
				for(int j=1;j<=n;j++)
					if(j!=i)
						printf("%d %d\n",i,j);
				break;
			}
	}
}