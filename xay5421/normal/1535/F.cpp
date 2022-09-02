// author: xay5421
// created: Fri Jun  4 22:36:33 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=200005;
int n;
LL ans;
struct node{
	string s;
	vector<int>cnt;
	bool operator<(const node&k)const{
		return cnt!=k.cnt?cnt<k.cnt:s<k.s;
	}
}a[N];
LL C2(LL x){return x*(x-1)>>1;}
struct SAM{
	const static int N=::N*4;
	int n,lst,cnt,ch[N][27],fa[N],len[N],sz[N];
	void clear(){
		while(cnt){
			memset(ch[cnt],0,sizeof(ch[cnt]));
			fa[cnt]=0;
			len[cnt]=0;
			sz[cnt]=0;
			--cnt;
		}
		lst=cnt=1;
	}
	void ps(int c){
		int p=lst,np=lst=++cnt; len[np]=len[p]+1,sz[np]=1;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(!p){fa[np]=1;return;}
		int q=ch[p][c];
		if(len[p]+1==len[q]){fa[np]=q;return;}
		int nq=++cnt; len[nq]=len[p]+1,sz[nq]=0;
		memcpy(ch[nq],ch[q],sizeof(ch[nq]));
		fa[nq]=fa[q],fa[q]=fa[np]=nq;
		for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
	}
	int bin[N],ord[N];
	void bud(const string&str){
		clear();
		rep(i,0,SZ(str)-1){
			ps(str[i]-'a');
		}
		n=SZ(str);
		memset(bin,0,sizeof(bin[0])*(cnt+1));
		rep(i,1,cnt)++bin[len[i]];
		rep(i,1,n)bin[i]+=bin[i-1];
		rep(i,1,cnt)ord[bin[len[i]]--]=i;
		per(i,cnt,1){
			int p=ord[i];
			sz[fa[p]]+=sz[p];
		}
	}
}sam;
void calc(const string&s,int same){
	ans-=C2(same)*2;
	int p=1,len=0;
	rep(i,0,SZ(s)-1){
		p=sam.ch[p][s[i]-'a'];
		++len;
	}
	p=sam.ch[p][26];
	++len;
	assert(p);
	
	for(int i=0,j;i<SZ(s);i=j){
		j=i+1;
		while(j<SZ(s)&&s[j-1]<=s[j])++j;
		len-=j-i;
		while(len<=sam.len[sam.fa[p]])p=sam.fa[p];
		ans-=sam.sz[p]-same;
		rep(k,i,j-1)p=sam.ch[p][s[k]-'a'];
		len+=j-i;
		assert(p);
	}
}
void sol(int l,int r){
	ans+=C2(r-l+1)*2;
	string str="";
	rep(i,l,r)str+=a[i].s+"{"+a[i].s;
	sam.bud(str);
	for(int i=l,j;i<=r;i=j){
		j=i+1;
		while(j<=r&&a[j].s==a[i].s)++j;
		calc(a[i].s,j-i);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n){
		a[i].cnt.assign(26,0);
		cin>>a[i].s;
		for(auto x:a[i].s)++a[i].cnt[x-'a'];
	}
	sort(a+1,a+1+n);
	for(int i=1,j;i<=n;i=j){
		j=i+1;
		while(j<=n&&a[j].cnt==a[i].cnt)++j;
		sol(i,j-1);
		ans+=1337LL*(j-i)*(i-1);
	}
	printf("%lld\n",ans);
	return 0;
}