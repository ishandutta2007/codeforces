#include<bits/stdc++.h>
using namespace std;
const long long p=998244353,g=3;
int N,o;
long long qow(long long a,long long n){//a>=0
    long long ans=1;
    for(a%=p;n;n>>=1){
    	if(n&1) ans=(ans*a)%p;
    	a=(a*a)%p;
	}
	return ans;
}
long long inverse(long long a){//a>=0
	return qow(a,p-2);
}
const long long gi=inverse(g);
long long f[1<<21];
int rev[1<<21];
void getrev(){
	for(int i=0;i<N;i++){
		rev[i]=0;
		for(int j=0;j<o;j++){
			if((i>>j)&1) rev[i]^=(1<<(o-1-j));
		}
	}
}
void fft(int type){
	for(int i=0;i<N;i++){
		if(rev[i]>i){
			long long u=f[i];
			f[i]=f[rev[i]];
			f[rev[i]]=u;
		}
	}
	for(int i=1;i<=o;i++){
		int M=(1<<(i-1));
		long long w=qow(type==1 ? g : gi,(p-1)>>i);
		for(int l=0;l<N;l+=(1<<i)){
			long long w1=1;
			for(int ll=l;ll<l+M;ll++){
			    long long x=(f[ll]+f[ll+M]*w1)%p,y=(f[ll]-f[ll+M]*w1)%p;
			    if(y<0) y+=p;
				f[ll]=x,f[ll+M]=y;	
				w1=(w1*w)%p;
			}
		}
	}
}
long long h[1<<21];
long long f2[1<<21];
long long g2[1<<21];
long long h2[1<<21];
void multiply(int n,int m){
	for(o=1;;o++){
		if((1<<o)>n+m+2) break;
	}
	N=(1<<o);
	getrev();
	for(int i=0;i<=n;i++) f[i]=f2[i];
	for(int i=n+1;i<N;i++) f[i]=0;
	fft(1);
	for(int i=0;i<N;i++) h[i]=f[i];
	for(int i=0;i<=m;i++) f[i]=g2[i];
	for(int i=m+1;i<=N;i++) f[i]=0;
	fft(1);
	for(int i=0;i<N;i++) f[i]=(f[i]*h[i])%p;
	fft(-1);
	long long inv=inverse(N);
	for(int i=0;i<=n+m;i++) h2[i]=(inv*f[i])%p;
}//
const int B=3000;
char s[300000];
char t[300000];
int ans[110][210000];
int ss[300000];
int tt[300000];
int main(){
	scanf("%s",s);
	scanf("%s",t);
	int n=strlen(s);
	int m=strlen(t);
	ss[0]=0;
	for(int i=0;i<=n-1;i++) ss[i+1]=ss[i]+(s[i]-'0');
	tt[0]=0;
	for(int j=0;j<=m-1;j++) tt[j+1]=tt[j]+(t[j]-'0');
	for(int i=0;i<n/B;i++){
		for(int j=0;j<B;j++) f2[j]=s[i*B+B-1-j]-'0';
		for(int j=0;j<m;j++) g2[j]=t[j]-'0';
		multiply(B-1,m-1);
		for(int j=0;j<=m-B;j++) ans[i][j]=ss[i*B+B]-ss[i*B]+tt[j+B]-tt[j]-2*h2[j+B-1];
	}
	int q;
	scanf("%d",&q);
	for(int o=1;o<=q;o++){
		int p1,p2,len;
		scanf("%d%d%d",&p1,&p2,&len);
		int r=p1+len-1;
		int anss=0;
		if(p1/B==r/B){
			for(int i=p1;i<=r;i++)
				if(s[i]!=t[i-p1+p2]) anss++;
		}
		else{
			int u1=(p1/B+1)*B-1;
			for(int i=p1;i<=u1;i++) 
			    if(s[i]!=t[i-p1+p2]) anss++;
			for(int i=(r/B)*B;i<=r;i++)
			    if(s[i]!=t[i-p1+p2]) anss++;
			int u2=r/B-1;
			for(int i=p1/B+1;i<=u2;i++) anss+=ans[i][i*B-p1+p2];
		}
		printf("%d\n",anss);
	}
	return 0;
}