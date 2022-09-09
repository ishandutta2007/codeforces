#include <bits/stdc++.h>
using namespace std;
const int N=2000050;
struct SuffixAutomaton{
	int lst,len[N],lnk[N],sz[N],tsz,rt,ord[N],cnt[N];
	map<char,int> go[N];
	SuffixAutomaton(){}
	void init(){rt=lst=++tsz;lnk[tsz]=len[tsz]=0;}
	void Extend(char c){
		tsz++;sz[tsz]=1;
		len[tsz]=len[lst]+1;
		int p=lst;
		lst=tsz;
		while(p&&!go[p].count(c))go[p][c]=tsz,p=lnk[p];
		if(!p)lnk[tsz]=rt;
		else{
			int q=go[p][c];
			if(len[q]==len[p]+1)lnk[tsz]=q;
			else{
				int nq=tsz+1;
				len[nq]=len[p]+1;
				go[nq]=go[q];
				lnk[nq]=lnk[q];
				lnk[q]=lnk[tsz]=nq;
				while(p&&go[p][c]==q)go[p][c]=nq,p=lnk[p];
				tsz++;
			}
		}
	}
	void Build(){
		for(int i=1;i<=tsz;i++)cnt[i]=0;
		for(int i=2;i<=tsz;i++)cnt[len[i]]++;
		for(int i=1;i<=tsz;i++)cnt[i]+=cnt[i-1];
		for(int i=2;i<=tsz;i++)ord[cnt[len[i]]--]=i;
		for(int j=tsz-1,i;i=ord[j],j>=1;j--)sz[lnk[i]]+=sz[i];
	}
}SA;
char s[N];
int kmp[2*N];
char str[2*N];
int GetT(int l,int r){
	int n=r-l+1;
	for(int i=1;i<=n;i++)str[i]=str[i+n]=s[l+i-1];
	kmp[0]=kmp[1]=0;
	for(int i=2;i<=n*2;i++){
		int on=kmp[i-1];
		while(on&&str[on+1]!=str[i])on=kmp[on];
		if(str[on+1]==str[i])on++;
		kmp[i]=on;
		if(kmp[i]==n)return i-n;
	}
	return n;
}
int was[N];
int main(){
	SA.init();
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++)SA.Extend(s[i]);
	SA.Build();
	int q;
	scanf("%i",&q);
	while(q--){
		scanf("%s",s);
		int m=strlen(s);
		int ans=0;
		int per=GetT(0,m-1);
		for(int i=0,now=SA.rt,cur=0;i<m+per-1;i++){
			char c=s[i%m];
			while(now&&!SA.go[now][c])now=SA.lnk[now],cur=SA.len[now];
			if(SA.go[now][c])now=SA.go[now][c],cur++;
			else now=SA.rt,cur=0;
			if(cur>=m){
				while(now&&SA.len[SA.lnk[now]]>=m)
					now=SA.lnk[now],cur=SA.len[now];
				ans+=SA.sz[now];
				//printf("(%i %i)",now,SA.sz[now]);
			}
		}
		printf("%i\n",ans);
	}
	return 0;
}