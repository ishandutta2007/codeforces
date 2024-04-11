#include<cstdio>
#include<cmath>
#define N 20005

int T;

int n,u,v,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&u,&v);
		int flg=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i>1&&a[i]!=a[i-1]&&!flg)
				flg=1;
			if(i>1&&std::abs(a[i]-a[i-1])>1&&flg==1)
				flg=2;
		}
		if(!flg)
			printf("%d\n",std::min(u+v,v+v));
		if(flg==1)
			printf("%d\n",std::min(u,v));
		if(flg==2)
			puts("0");
	}
}