#include<bits/stdc++.h>

using namespace std;

namespace io{
	const int L=(1<<19)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
	char gc(){
		if(iS==iT){
			iT=(iS=ibuf)+fread(ibuf,1,L,stdin);
			return iS==iT?EOF:*iS++;
		}
		return*iS++;
	}
	void cbuf(){fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
	void putc(char x){*oS++=x;if(oS==oT)cbuf();}
	void gs(char*s){
		for(c=gc();c>'z'||c<'a';c=gc());
		for(;c>='a'&&c<='z';c=gc())*s++=c;
	}
	template<class I>void gi(I&x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
	void ps(char*s){while(*s)putc(*s++);}
	template<class I>void print(I x){
		if(!x)putc('0');if(x<0)putc('-'),x=-x;
		while(x)st[++tp]=x%10+'0',x/=10;
		while(tp)putc(st[tp--]);
	}
	void scan(int l,...){
		va_list scan;
		va_start(scan,l);
		while(l)gi(*va_arg(scan,int*)),l--;
		va_end(scan);
	}
};
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::scan;
using io::print;

const int N=300005,M=20;

struct maxst{
	int st[M][N],lg[N],n;
	void init(int*p,int m){
		n=m;memcpy(st[0]+1,p+1,n<<2);
		for(int l=2,i=1;l<=n;l<<=1,i++)for(int j=1;j<=n-l+1;j++)
			st[i][j]=max(st[i-1][j],st[i-1][j+(l>>1)]);
		for(int i=2;i<=n;i++)lg[i]=lg[i-1]+!(i&i-1);
	}
	int ask(int l,int r){
		int d=lg[r-l+1];
		return max(st[d][l],st[d][r-(1<<d)+1]);
	}
}A,B;
int n,a[N],b[N];

int main(){
	gi(n);
	for(int i=1;i<=n;i++)gi(a[i]);
	for(int i=1;i<n;i++)b[i]=min(a[i],a[i+1]);
	A.init(a,n),B.init(b,n-1);
	for(int k=1,ans;k<n;k++){
		int l=n-k+1;
		if(l&1)ans=B.ask(l>>1,n-(l>>1));
		else ans=A.ask(l>>1,n-(l>>1)+1);
		print(ans),putc('\n');
	}
	print(A.ask(1,n)),io::cbuf();
	return 0;
}