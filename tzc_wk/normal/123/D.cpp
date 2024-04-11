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
const int MAXN=1e5;
const int LOG_N=17;
int n,m=0;char s[MAXN+5];pii x[MAXN+5];
int sa[MAXN+5],rk[MAXN+5],buc[MAXN+5],seq[MAXN+5],ht[MAXN+5];
int hd[MAXN+5],v[MAXN+5],nxt[MAXN+5],vn=0;
void ins(int x,int y){v[++vn]=y;nxt[vn]=hd[x];hd[x]=vn;}
void getsa(){
	int vmax=122,gr=0;
	for(int i=1;i<=n;i++) buc[s[i]]++;
	for(int i=1;i<=vmax;i++) buc[i]+=buc[i-1];
	for(int i=1;i<=n;i++) sa[buc[s[i]]--]=i;
	for(int i=1;i<=n;i++){
		if(s[sa[i]]!=s[sa[i-1]]) gr++;
		rk[sa[i]]=gr;
	} vmax=gr;
	for(int k=1;k<=n;k<<=1){
		for(int i=1;i<=n;i++){
			if(i+k<=n) x[i]=mp(rk[i],rk[i+k]);
			else x[i]=mp(rk[i],0);
		} memset(buc,0,sizeof(buc));gr=0;int num=0;
		for(int i=n-k+1;i<=n;i++) seq[++num]=i;
		for(int i=1;i<=n;i++) if(sa[i]>k) seq[++num]=sa[i]-k;
		for(int i=1;i<=n;i++) buc[x[i].fi]++;
		for(int i=1;i<=vmax;i++) buc[i]+=buc[i-1];
		for(int i=n;i;i--) sa[buc[x[seq[i]].fi]--]=seq[i];
		for(int i=1;i<=n;i++){
			if(x[sa[i]]!=x[sa[i-1]]) gr++;
			rk[sa[i]]=gr;
		} vmax=gr;if(vmax==n) break;
	}
}
void getht(){
	int k=0;
	for(int i=1;i<=n;i++){
		if(rk[i]==1) continue;if(k) --k;
		int j=sa[rk[i]-1];
		while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) k++;
		ht[rk[i]]=k;
	}
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);getsa();getht();
	for(int i=2;i<=n;i++) ins(ht[i],i);ll sum=1ll*n*(n+1)/2,ans=0;
	set<int> st;st.insert(1);st.insert(n+1);
	for(int i=1;i<=n;i++){
		for(int e=hd[i-1];e;e=nxt[e]){
			int id=v[e];st.insert(id);
			set<int>::iterator it=st.find(id);
			int pre=*--it;++it;
			int nxt=*++it;--it;
			sum-=1ll*(nxt-pre)*(nxt-pre+1)/2;
			sum+=1ll*(id-pre)*(id-pre+1)/2;
			sum+=1ll*(nxt-id)*(nxt-id+1)/2;
		} ans+=sum;
	} ans-=1ll*n*(n-1)/2;printf("%lld\n",ans);
	return 0;
}