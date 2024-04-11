#include <stdio.h>
#include <memory.h>

#define MAXN 100500

int res,n,m,T[MAXN],C[MAXN],l,r,t,c;

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++)T[i]=1000000000;
	memset(C,0,sizeof(C));
	for (int i=0;i<m;i++){
		scanf("%d%d%d%d",&l,&r,&t,&c);
		for (int j=l;j<=r;j++)
			if (t<T[j]){
				T[j]=t;
				C[j]=c;
			}
	}
	int res=0;
	for (int i=0;i<=n;i++)res+=C[i];
	printf("%d\n",res);
}