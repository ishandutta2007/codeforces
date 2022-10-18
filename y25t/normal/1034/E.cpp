#include<bits/stdc++.h>
#define pc(i) __builtin_popcount(i)
#define ll long long
#define N (1<<21)

int n;
char s[N+5],t[N+5];

ll a[N],b[N],c[N];

inline void fwt(ll *f,int tp){
	for(int k=1;k<(1<<n);k<<=1)
		for(int i=0;i<(1<<n);i+=k<<1)
			for(int j=0;j<k;j++)
				f[i+j+k]+=tp*f[i+j];
}

int main(){
	scanf("%d%s%s",&n,s,t);
	for(int i=0;i<(1<<n);i++)
		a[i]=(ll)(s[i]-'0')<<(pc(i)<<1),b[i]=(ll)(t[i]-'0')<<(pc(i)<<1);
	fwt(a,1),fwt(b,1);
	for(int i=0;i<(1<<n);i++)
		c[i]=a[i]*b[i];
	fwt(c,-1);
	for(int i=0;i<(1<<n);i++)
		putchar('0'+((c[i]>>(pc(i)<<1))&3));
}