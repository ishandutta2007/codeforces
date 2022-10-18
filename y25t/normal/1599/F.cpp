#include<bits/stdc++.h>
#define P 1000000007
#define N 200005

inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k=P-2){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

const int W=37;
int C[W+1][W+1];
inline void init(){
	for(int i=0;i<=W;i++)
		C[i][0]=1;
	for(int i=1;i<=W;i++)
		for(int j=1;j<=i;j++)
			C[i][j]=fmo(C[i-1][j]+C[i-1][j-1]-P);
}

int n,q,a[N];

int b[N],c[W+1][N];

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]=fmo(a[i]+114514-P);
	c[0][0]=1;
	for(int i=1;i<=n;i++){
		int tmp=1;
		for(int j=0;j<=W;j++,tmp=1ll*tmp*i%P)
			c[j][i]=fmo(c[j][i-1]+tmp-P);
		b[i]=fmo(b[i-1]+fp(a[i],W)-P);
		a[i]=fmo(a[i]+a[i-1]-P);
	}
	init();
	while(q--){
		int L,R,d;
		scanf("%d%d%d",&L,&R,&d);
		int l=R-L+1,s=1ll*fp(l)*fmo(fmo(a[R]-a[L-1])-1ll*l*(l-1)/2%P*d%P)%P;
		int res=0;
		for(int i=0;i<=W;i++)
			res=fmo(res+1ll*C[W][i]*fp(s,i)%P*fp(d,W-i)%P*c[W-i][l-1]%P-P);
		puts(res==fmo(b[R]-b[L-1])?"Yes":"No");
	}
}