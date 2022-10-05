#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e5;
const int MOD=998244353;
int n,a[MAXN+5];ll s[MAXN+5],s1[MAXN+5],s2[MAXN+5];
void solve(){
	scanf("%d",&n);ll lim=0,ans=1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	lim=(s[n]-1)>>1;
	for(int i=3;i<=n;i++) ans+=(s[n]-s[i-1]<=lim);
	for(int i=1;i<=n;i++){
		if(i&1) s1[i+1>>1]=s1[i-1>>1]+a[i];
		else s2[i+1>>1]=s2[i-1>>1]+a[i];
	}
	for(int i=1;i<=2;i++){
		for(int j=i;j<=n;j++){
			ll sum=s[j]-s[i-1];
			if(sum>lim) continue;
			if(j&1){
				int pos=upper_bound(s1+1,s1+(n+1>>1)+1,lim+s1[(j+1)>>1]-sum)-s1;
				ans+=pos-((j+1)>>1);
			} else {
				int pos=upper_bound(s2+1,s2+(n>>1)+1,lim+s2[(j+1)>>1]-sum)-s2;
				ans+=pos-(j>>1);
			}
			if(j>=n-2) continue;
			if(sum+a[n]>lim) continue;
			if(j&1){
				int pos=upper_bound(s1+1,s1+(n-2>>1)+1,lim+s1[(j+1)>>1]-a[n]-sum)-s1;
				ans+=pos-((j+1)>>1);
			} else {
				int pos=upper_bound(s2+1,s2+(n-3>>1)+1,lim+s2[(j+1)>>1]-a[n]-sum)-s2;
				ans+=pos-(j>>1);
			}
//			for(int k=j;k<=n;k+=2){
//				if(k!=j) sum+=a[k];
//				ans+=(sum<=lim);
//				if(k<n-2) ans+=(sum+a[n]<=lim);
//			}
		}
	} printf("%d\n",ans%MOD);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}