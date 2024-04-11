#include<bits/stdc++.h>

#define mms(x,n) memset(x,0,sizeof((x)[0])*n)
#define mmp(x,y,n) memset(x,y,sizeof((y)[0])*n)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define abs abs_

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef map<int,int> mii;

namespace io{
	const int L=(1<<19)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
	inline char gc(){
		if(iS==iT){
			iT=(iS=ibuf)+fread(ibuf,1,L,stdin);
			return iS==iT?EOF:*iS++;
		}
		return*iS++;
	}
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
};
using io::putc;
using io::gi;
using io::print;

const int N=1000005,M=100005,P=1e9+7;

int T,n,m,a[N],w[N],p1[N],cnt[N],vi[N],mx[N],sum[N],pri[M],pc,fac[N],ans;
bool fl[N],p2[N];

void shaker(){
	fac[0]=fac[1]=sum[1]=mx[1]=1;fl[1]=true;
	for(int i=2;i<N;i++){
		if(!fl[i])pri[++pc]=i,mx[i]=i,sum[i]=i;
		for(int j=1;i*pri[j]<N;j++){
			fl[i*pri[j]]=true;
			mx[i*pri[j]]=mx[i];
			if(i%pri[j]==0){sum[i*pri[j]]=sum[i];break;}
			sum[i*pri[j]]=sum[i]*pri[j];
		}
		fac[i]=(ll)fac[i-1]*i%P;
	}
}

int main(){
	shaker();T=1;
	while(T--){
		gi(n);
		for(int i=1;i<=n;i++)gi(a[i]);
		for(m=0;m*m<=n;m++);
		for(int i=1;i<=n;i++)w[i]=sum[i]/(mx[i]>=m?mx[i]:1);
		mx[1]=n+1;w[1]=1;
		bool ok=true;
		for(int i=1;i<=n;i++)if(a[i]){
			if(w[i]!=w[a[i]]){ok=false;break;}
			if(mx[a[i]]>=m){
				int t=mx[a[i]];
				if(max(n/mx[i],1)!=max(n/t,1)||vi[t]>0&&vi[t]!=mx[i]){ok=false;break;}
				vi[t]=mx[i];
			}
		}
		if(ok){
			for(int i=1;i<=n;i++)p1[sum[i]]++;
			for(int i=1;i<=n;i++)if(a[i]){
				p1[sum[a[i]]]--;
				if(mx[a[i]]>=m)p2[mx[a[i]]]=true;
			}
			ans=1;
			for(int i=1;i<=n;i++)if(p1[i])ans=(ll)ans*fac[p1[i]]%P;
			for(int i=m;i<=n;i++)if(!fl[i]&&!p2[i])cnt[n/i]++;
			if(!p2[n+1])cnt[1]++;
			for(int i=1;i<=m;i++)ans=(ll)ans*fac[cnt[i]]%P;
		}
		print(ans);putc('\n');
		for(int i=0;i<=n+1;i++)a[i]=w[i]=p1[i]=cnt[i]=vi[i]=p2[i]=0;ans=n=m=0;
	}
	io::flush();
	return 0;
}