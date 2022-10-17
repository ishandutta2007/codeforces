#include <unordered_set>
#include <cstdio>
#include <cstring>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define N 2000005
#define P 19260817
typedef long long ll;
typedef unsigned long long ull;

int n,lenn;
char s[N];
ll ans;
ull pw[N],ha[N];
std::unordered_set <ull> S;

ull get(int l,int r){
	if (l==0) return ha[r];
	return ha[r]-ha[l-1]*pw[r-l+1];
}

struct SAM{
	int lst,cnt;
	int fa[N],ch[N][26];
	int len[N],siz[N];
	int bin[N],ord[N];
	SAM(){lst=cnt=1;}
	void extend(int c){
		int p=lst,np=lst=++cnt; len[np]=len[p]+1,siz[np]=1;
		for (;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
		if (!p) fa[np]=1;
		else{
			int q=ch[p][c];
			if (len[p]+1==len[q]) fa[np]=q;
			else{
				int nq=++cnt; len[nq]=len[p]+1;
				memcpy(ch[nq],ch[q],sizeof(ch[nq])),fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				for (;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
			}
		}
	}
	void sort(){
		rep (i,1,cnt) ++bin[len[i]];
		rep (i,1,cnt) bin[i]+=bin[i-1];
		rep (i,1,cnt) ord[bin[len[i]]--]=i;
		per (i,cnt,1){
			int p=ord[i];
			siz[fa[p]]+=siz[p];
		}
	}
	void calc(){
		int p=1,lenth=0; ans=0; S.clear();
		for (int i=0;i<lenn+lenn;++i){
			bool flag=0;
			if (i>=lenn-1) flag=S.count(get(i-lenn+1,i)),S.insert(get(i-lenn+1,i));
			int c=s[i]-'a';
			for (;p&&!ch[p][c];p=fa[p],lenth=len[p]);
			if (!p) p=1,lenth=0;
			else{
				p=ch[p][c],++lenth;
				for (;len[fa[p]]>=lenn;p=fa[p],lenth=len[p]);
				if (lenth>=lenn&&!flag) ans+=siz[p];
			}
		}
	}
} sam;

int main(){
	scanf("%s",s);
	for (int i=0;s[i];++i) sam.extend(s[i]-'a');
	sam.sort();
	scanf("%d",&n);
	pw[0]=1; rep (i,1,N-1)  pw[i]=pw[i-1]*P;
	for (int i=1;i<=n;++i){
		scanf("%s",s); lenn=strlen(s);
		for (int i=lenn;i<lenn+lenn;++i) s[i]=s[i-lenn]; s[lenn+lenn]=0;
		ha[0]=s[0]-'a'+1; for (int i=1;i<lenn+lenn;++i) ha[i]=ha[i-1]*P+s[i]-'a'+1;
		sam.calc();
		printf("%I64d\n",ans);
	}
	return 0;
}