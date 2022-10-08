#include<bits/stdc++.h>

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define lowbit(x) ((x)&-(x))
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r;_lim_=l;i>=_lim_;i--)

using namespace std;
typedef long long ll;
typedef pair<int,ll> pi;

namespace io{
	const int L=(1<<21)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
	#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	inline void flush(){fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
	inline void putc(char x){*oS++=x;if(oS==oT)flush();}
	template<class I>
	inline void gi(I&x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
	template<class I>
	inline void print(I x){
		if(!x)putc('0');if(x<0)putc('-'),x=-x;
		while(x)st[++tp]=x%10+'0',x/=10;
		while(tp)putc(st[tp--]);
	}
	inline void gs(char*s,int&l){
		for(c=gc();c!='_'&&(c<'a'||c>'z');c=gc());
		for(l=0;c=='_'||c<='z'&&c>='a';c=gc())s[l++]=c;
	}
};
using io::putc;
using io::gi;
using io::gs;
using io::print;

const int N=405,M=610,P=10007;
inline int fpow(int a,int t){
	static int r;a%=P,t%=P-1;
	for(r=1;t;t>>=1,a=a*a%P)if(t&1)r=r*a%P;
	return r;
}

char s[N];
int a[M][M],n,t,maxA,maxB,m,D,ans;
int dp[N<<1][N][N];

inline void upd(int i,int j,int k,int w){
	if(k<0)k=0;if(j>m+1)j=m+1;
	dp[i][j][k]=(dp[i][j][k]+w)%P;
}

int main(){
//	freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
	gs(s+1,m);gi(n);t=(m+n+1)/2;
	maxA=m;maxB=(m+3)>>1;D=maxA+maxB+1;
	dp[0][1][m]=1;
	for(int i=0;i<D+m/2;i++){
		for(int j=0;j<=m+1;j++)for(int k=0;k<=m+1;k++)if(dp[i][j][k]){
			if(j>k)
				upd(i+1,j,k,dp[i][j][k]*26);
			else if(s[j]==s[k])
				upd(i+1,j+1,k-1,dp[i][j][k]),upd(i+1,j,k,dp[i][j][k]*25);
			else
				upd(i+1,j+1,k,dp[i][j][k]),upd(i+1,j,k-1,dp[i][j][k]),upd(i+1,j,k,dp[i][j][k]*24);
		}
	}
	for(int T=1,l=(m+n)&1;T<=D;T++){
		while(l<=m+(T-1)*2)l+=2;
		int p=l/2,w=0;
		for(int i=0;i<=m+1;i++)for(int j=0;j<i;j++)if(dp[p][i][j])w=(w+dp[p][i][j])%P;
		if(l&1){
			w=w*26%P;
			for(int i=1;i<=m;i++)w=(w+dp[p][i][i])%P;
		}
		if(l==n+m)printf("%d\n",w),exit(0);
		int t=(l+1)/2;
		a[T][0]=w;
		for(int i=0;i<maxA;i++)
			a[T][i+1]=fpow(24,t)*fpow(t,i)%P;
		for(int i=0;i<maxB;i++)
			a[T][i+maxA+1]=fpow(25,t)*fpow(t,i)%P;
		a[T][maxA+maxB+1]=fpow(26,t);
	}
	for(int i=1;i<=D;i++){
		int l=i;while(!a[l][i]&&l<=D)l++;assert(l<=D);
		if(i!=l)for(int j=0;j<=D;j++)swap(a[i][j],a[l][j]);
		int t=fpow(a[i][i],P-2);
		for(int j=0;j<=D;j++)a[i][j]=a[i][j]*t%P;
		for(int j=1;j<=D;j++)if(i!=j){
			t=a[j][i];if(!t)continue;
			for(int k=i;k<=D;k++)a[j][k]=((a[j][k]-t*a[i][k])%P+P)%P;
			a[j][0]=((a[j][0]-a[i][0]*t)%P+P)%P;
		}
	}
	for(int i=0;i<maxA;i++)
		ans=(ans+a[i+1][0]*fpow(24,t)%P*fpow(t,i))%P;
	for(int i=0;i<maxB;i++)
		ans=(ans+a[i+maxA+1][0]*fpow(25,t)%P*fpow(t,i))%P;
	ans=(ans+a[maxA+maxB+1][0]*fpow(26,t))%P;
	printf("%d\n",ans);
	return 0;
}