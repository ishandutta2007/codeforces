#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
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
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=2e5;
const int MAXT=1e8;
char s[MAXN+5];ll ans=0;
int n,a[MAXN+5],sum[MAXN+5],hst[MAXT+5],blk_sz=0;
int main(){
	scanf("%s",s+1);n=strlen(s+1);blk_sz=(int)pow(n,0.5);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]^48);
	for(int k=1;k<=blk_sz;k++){
		for(int i=0;i<=n;i++) a[i]=k*sum[i]-i+n;
		for(int i=0;i<=n;i++) hst[a[i]]++;
		for(int i=0;i<=n;i++) ans+=1ll*hst[a[i]]*(hst[a[i]]-1)/2,hst[a[i]]=0;
	}
	for(int k=1;k<=n/blk_sz;k++){
		int l=0,r=0;
		for(int i=1;i<=n;i++){
			while(sum[l]-sum[i-1]<k&&l<=n) l++;
			if(l==n+1) break;
			while(sum[r]-sum[i-1]<=k&&r<=n) r++;
			if((r-i)/k>blk_sz) ans+=(r-i)/k-max((l-i)/k,blk_sz);
		}
	} printf("%lld\n",ans);
	return 0;
}