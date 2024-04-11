#include<bits/stdc++.h>
#define N 100005
#define W 19

int n,q;

#define pii std::pair<int,int>
#define fr first
#define sc second
pii operator + (pii x,pii y){
	return pii(std::min(x.fr,y.fr),std::max(x.sc,y.sc));
}

pii f[N][W][W];
inline pii F(pii x,int i){
	int k=std::__lg(x.sc-x.fr+1);
	return f[x.fr][k][i]+f[x.sc-(1<<k)+1][k][i];
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		f[i][0][0]=pii(x,x);
	}
	for(int j=1;j<W;j++) for(int i=1;i+(1<<j)-1<=n;i++)
		f[i][j][0]=f[i][j-1][0]+f[i+(1<<(j-1))][j-1][0];
	for(int k=1;k<W;k++) for(int j=0;j<W;j++) for(int i=1;i+(1<<j)-1<=n;i++)
		f[i][j][k]=F(f[i][j][k-1],k-1);
	while(q--){
		pii x;
		scanf("%d%d",&x.fr,&x.sc);
		if(x==pii(1,n)){
			puts("0");
			continue;
		}
		int res=0;
		for(int i=W-1;~i;i--){
			pii y=F(x,i);
			if(y.fr>1||y.sc<n)
				x=y,res|=1<<i;
		}
		x=F(x,0),res++;
		printf("%d\n",x==pii(1,n)?res:-1);
	}
}