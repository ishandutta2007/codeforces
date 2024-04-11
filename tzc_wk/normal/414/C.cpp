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
const int MAXN=1<<20;
const int MAXM=20;
int n,m,v[MAXN+5];ll c1[MAXM+5],c2[MAXM+5];
vector<int> cdq1(int l,int r,int stp){
	if(l==r){vector<int> tmp;tmp.pb(v[l]);return tmp;}
	int mid=l+r>>1;
	vector<int> a=cdq1(l,mid,stp-1);
	vector<int> b=cdq1(mid+1,r,stp-1);
	for(int i=0,j=0;i<b.size();i++){
		while(j<a.size()&&a[j]<=b[i]) ++j;
		c1[stp]+=a.size()-j;
	} vector<int> c;c.clear();
	for(int i=0,j=0;i<a.size()||j<b.size();){
		if(i>=a.size()) c.push_back(b[j]),j++;
		else if(j>=b.size()||a[i]<b[j]) c.push_back(a[i]),i++;
		else c.push_back(b[j]),j++;
	} return c;
}
vector<int> cdq2(int l,int r,int stp){
	if(l==r){vector<int> tmp;tmp.pb(v[l]);return tmp;}
	int mid=l+r>>1;
	vector<int> a=cdq2(l,mid,stp-1);
	vector<int> b=cdq2(mid+1,r,stp-1);
	for(int i=0,j=0;i<b.size();i++){
		while(j<a.size()&&a[j]<b[i]) ++j;
		c2[stp]+=j;
	} vector<int> c;
	for(int i=0,j=0;i<a.size()||j<b.size();){
		if(i>=a.size()) c.push_back(b[j]),j++;
		else if(j>=b.size()||a[i]<b[j]) c.push_back(a[i]),i++;
		else c.push_back(b[j]),j++;
	} return c;
}
bool is[MAXM+5];
int main(){
	scanf("%d",&m);n=1<<m;
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	vector<int> tot=cdq1(1,n,m);
	tot=cdq2(1,n,m);ll ans=0;
	for(int i=1;i<=m;i++) ans+=c1[i];
	int qu;scanf("%d",&qu);
	for(int i=1;i<=qu;i++){
		int x;scanf("%d",&x);
		for(int j=1;j<=x;j++){
			if(is[j]) ans-=c2[j],ans+=c1[j];
			else ans-=c1[j],ans+=c2[j];
			is[j]^=1;
		} printf("%lld\n",ans);
	}
	return 0;
}