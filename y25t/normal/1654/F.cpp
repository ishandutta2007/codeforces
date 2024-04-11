#include<bits/stdc++.h>
#define ull unsigned long long
#define N (1<<18)
 
int n;
int a[N+1024];
char s[N+1024];
 
#define P 998244353
#define B 37
int b[N+1024];
 
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
 
inline void fwt(int *f,int tp){
	for(int k=1;k<N;k<<=1)
		for(int i=0;i<N;i+=k<<1)
			for(int j=0;j<k;j++){
				int x=f[i+j],y=f[i+j+k];
				f[i+j]=fmo(x+y-P);
				f[i+j+k]=fmo(x-y);
			}
	if(tp==-1){
		int tmp=fp(N);
		for(int i=0;i<N;i++)
			f[i]=1ll*f[i]*tmp%P;
	}
}
 
inline bool cmp(int x,int y){
	for(int i=0;i<(1<<9)&&(i<<9)<=n;i++){
		if(b[x^(i<<9)]==b[y^(i<<9)])
			continue;
		for(int j=0;j<(1<<9)&&(i<<9|j)<=n;j++){
			int t=i<<9|j;
			if(s[t^x]!=s[t^y])
				return s[t^x]<s[t^y];
		}
		break;
	}
	return 0;
}
 
int main(){
	scanf("%d%s",&n,s);
	n=1<<n;
	for(int i=0;i<n;i++)
		a[i]=s[i]-'a'+1;
	b[0]=1;
	for(int i=1;i<(1<<9);i++)
		b[i]=1ll*b[i-1]*B%P;
	fwt(a,1),fwt(b,1);
	for(int i=0;i<N;i++)
		b[i]=1ll*b[i]*a[i]%P;
	fwt(b,-1);
	int ans=0;
	for(int i=1;i<n;i++)
		if(cmp(i,ans))
			ans=i;
	for(int i=0;i<n;i++)
		putchar(s[i^ans]);
	puts("");
}