#include<bits/stdc++.h>
#define dec _dec_
using namespace std;
typedef unsigned int u32;
const int N=1<<21|5;
char str[N];
int n,m,al,bit[N];
u32 f[N][2],g[N][2],h[N][2];
u32 to[277][277],up[277][277];
inline void inc(u32*u,u32*v){u[1]^=v[1]^(u[0]&v[0]),u[0]^=v[0];}
inline void dec(u32*u,u32*v){
	static u32 cc[2];
	cc[0]=~v[0]&al,cc[1]=~v[1]&al;
	inc(u,cc);
	cc[0]=al,cc[1]=0;
	inc(u,cc);
}
inline void mul(u32*a,u32*b,u32*c){
	int i,j,k;
	a[0]=a[1]=0;
	u32 b1=b[1],b0=b[0],c1=c[1],c0=c[0];
	for(i=0;i<3;i++)for(j=0;i+j<3;j++){
		u32 x1=b1>>(i*8)&255,x0=b0>>(i*8)&255;
		u32 y1=c1>>(j*8)&255,y0=c0>>(j*8)&255;
		u32 z0=to[x0][y0];
		u32 z1=to[x1][y0]^to[x0][y1]^up[x0][y0];
		z0<<=(i+j)*8;
		z1<<=(i+j)*8;
		u32 cur[2]={z0,z1};
		inc(a,cur);
	}
	a[0]&=al,a[1]&=al;
}
void fwt(u32 a[N][2]){
	int i,j,k,l;
	for(l=2;l<=m;l<<=1)for(j=0,i=l>>1;j<m;j+=l)for(k=0;k<i;k++)inc(a[j+k+i],a[j+k]);
}
void ifwt(u32 a[N][2]){
	int i,j,k,l;
	for(l=2;l<=m;l<<=1)for(j=0,i=l>>1;j<m;j+=l)for(k=0;k<i;k++)dec(a[j+k+i],a[j+k]);
}
int main(){
	int i,j,k,t,c;
	scanf("%d",&n),m=1<<n,al=2*m-1;
	for(i=1;i<m;i++)bit[i]=bit[i>>1]+(i&1);
	for(i=0;i<256;i++)for(j=0;j<256;j++){
		for(k=0;k<16;k++){
			c=0;
			for(t=0;t<=k;t++)c=(c+(i>>t&1)*(j>>(k-t)&1));
			c&=3;
			if(c&1)to[i][j]|=1<<k;
			if(c&2)up[i][j]|=1<<k;
		}
	}
	scanf("%s",str);
	for(i=0;i<m;i++){
		c=str[i]-'0';
		if(c&1)f[i][0]|=1<<bit[i];
		if(c&2)f[i][1]|=1<<bit[i];
	}
	scanf("%s",str);
	for(i=0;i<m;i++){
		c=str[i]-'0';
		if(c&1)g[i][0]|=1<<bit[i];
		if(c&2)g[i][1]|=1<<bit[i];
	}
	fwt(f),fwt(g);
	for(i=0;i<m;i++)mul(h[i],f[i],g[i]);
	ifwt(h);
	for(i=0;i<m;i++)str[i]='0'+(h[i][0]>>bit[i]&1)+(h[i][1]>>bit[i]&1)*2;
	puts(str);
}