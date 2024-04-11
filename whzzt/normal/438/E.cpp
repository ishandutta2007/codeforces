#include"bits/stdc++.h"

using namespace std;
typedef long long LL;

const int P=998244353,Inv2=P/2+1,N=100005,M=262200;

int power(int a,int t){
	int r=1;
	while(t){
		if(t&1)r=(LL)r*a%P;
		a=(LL)a*a%P;t>>=1;
	}
	return r;
}

int _wn[25];
void ntt(int*a,int len,int dft){
	int i,j=len>>1,k,l,c,w,wn,u,v,inv;
	for(i=1;i<len-1;i++){
		if(i>j)swap(a[i],a[j]);
		for(k=len>>1;(j^=k)<k;k>>=1);
	}
	if(!_wn[0]){
		for(_wn[i=23]=15311432;i;i--){
			_wn[i-1]=(LL)_wn[i]*_wn[i]%P;
		}
	}
	for(c=0,l=2;l<=len;l<<=1){
		for(wn=_wn[++c],i=l>>1,j=0;j<len;j+=l){
			for(w=1,k=j;k<j+i;k++,w=(LL)w*wn%P){
				u=a[k],v=(LL)a[k+i]*w%P;
				(a[k]=u+v)<P?:a[k]-=P;
				(a[k+i]=u-v)>=0?:a[k+i]+=P;
			}
		}
	}
	if(dft==-1){
		inv=power(len,P-2);
		for(i=1;i<len/2;i++)swap(a[i],a[len-i]);
		for(i=0;i<len;i++)a[i]=(LL)a[i]*inv%P;
	}
}

int wi1[M],wi2[M],wi3[M],wi4[M];
void inverse(int*a,int*t,int len){
	if(len==1){*t=power(*a,P-2);return;}
	inverse(a,wi1,len>>1);
	memset(wi2,0,len<<3);
	memset(wi3,0,len<<3);
	memcpy(wi2,wi1,len<<1);
	memcpy(wi3,a,len<<2);
	ntt(wi2,len<<1,1);
	ntt(wi3,len<<1,1);
	for(int i=0;i<(len<<1);i++)
		wi4[i]=((2*wi2[i]-(LL)wi2[i]*wi2[i]%P*wi3[i])%P+P)%P;
	ntt(wi4,len<<1,-1);
	memcpy(t,wi4,len<<2);
}

int ws1[M],ws2[M],ws3[M],ws4[M],ws5[M];
void sqrt(int*a,int*t,int len){
	if(len==1){
		for(register int x=1;x<P;x++)
			if((LL)x*x%P==*a){*t=x;return;}
		return;
	}
	sqrt(a,ws1,len>>1);
	memset(ws2,0,len<<3);
	memset(ws3,0,len<<3);
	memset(ws4,0,len<<3);
	memcpy(ws2,ws1,len<<1);
	memcpy(ws3,a,len<<2);
	inverse(ws2,ws4,len);
	ntt(ws2,len<<1,1);
	ntt(ws3,len<<1,1);
	ntt(ws4,len<<1,1);
	for(int i=0;i<(len<<1);i++)
		ws5[i]=((LL)ws2[i]*ws2[i]%P+ws3[i])*ws4[i]%P*Inv2%P;
	ntt(ws5,len<<1,-1);
	memcpy(t,ws5,len<<2);
}

int gl(int n){
	int l=1;
	while(l<=n*2)l<<=1;
	return l;
}

int n,m,c[N],H[M],T[M],R[M];

int main(){
	scanf("%d%d",&n,&m);
	H[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
		H[c[i]]=P-4;
	}
	sqrt(H,T,gl(m)>>1);
	T[0]++;
	inverse(T,R,gl(m)>>1);
	for(int i=1;i<=m;i++)printf("%d\n",R[i]*2%P);
	return 0;
}