#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=10050;
const int L=22;
/*struct EERTREE{
	char s[N];
	int tot,n,link[N][L],ZERO,IMAG,cur,len[N],go[N][26];
	EERTREE(){}
	void init(){
		for(int i=1;i<=tot;i++){
			for(int j=0;j<26;j++)go[i][j]=0;
			for(int j=0;j<L;j++)link[i][j]=0;
			len[i]=0;
		}
		tot=0;n=0;
		ZERO=++tot;len[ZERO]=0;link[ZERO][0]=IMAG;
		IMAG=++tot;len[IMAG]=0;link[IMAG][0]=ZERO;
		cur=IMAG;
	}
	int Expand(char c){
		s[++n]=c;
		while(s[n]!=s[n-len[cur]-1])cur=link[cur][0];
		if(!go[cur][c-'a']){
			int nxt=++tot;len[nxt]=len[cur]+2;
			go[cur][c-'a']=nxt;
			int tmp=link[cur][0];
			while(s[n]!=s[n-len[tmp]-1])tmp=link[tmp][0];
			if(cur!=IMAG)link[nxt][0]=go[tmp][c-'a'];
			else link[nxt][0]=ZERO;
		}
		cur=go[cur][c-'a'];
		return cur;
	}
	void Build(){
		for(int j=1;j<L;j++)for(int i=1;i<=tot;i++)link[i][j]=link[link[i][j-1]][j-1];
	}
	int GetLo(int node,int ln){
		for(int i=L-1;~i;i--)if(len[link[node][i]]>ln)node=link[node][i];
		if(len[node]<=ln)return len[node];
		else return len[link[node][0]];
	}
}FW,BW;*/
struct EERTREE
{
	map<int,int> go[N];
	int len[N],link[N],dif[N],jump[N],ZERO,IMAG,tsz,sz,at,par[N][L];
	char s[N];
	void init()
	{
		for(int i=1;i<=tsz;i++){
			len[i]=link[i]=dif[i]=jump[i]=0;
			go[i].clear();
			for(int j=0;j<L;j++)par[i][j]=0;
		}
		tsz=0;sz=0;
		IMAG=++tsz;link[IMAG]=IMAG;dif[IMAG]=-1;jump[IMAG]=IMAG;len[IMAG]=-1;
		ZERO=++tsz;link[ZERO]=IMAG;dif[ZERO]=-1;jump[ZERO]=IMAG;len[ZERO]=0;
		at=ZERO;
	}
	EERTREE(){ init();}
	int Expand(char c)
	{
		s[++sz]=c;
		while(s[sz]!=s[sz-len[at]-1]) at=link[at];
		if(!go[at][c-'a'])
		{
			int to=++tsz;len[to]=len[at]+2;link[to]=link[at];
			while(s[sz]!=s[sz-len[link[to]]-1]) link[to]=link[link[to]];
			if(at==IMAG) link[to]=ZERO;
			else link[to]=go[link[to]][c-'a'];
			dif[to]=len[to]-len[link[to]];
			if(dif[to]==dif[link[to]]) jump[to]=jump[link[to]];
			else jump[to]=link[to];
			go[at][c-'a']=to;
		}
		return at=go[at][c-'a'];
	}
	void Build(){
		for(int i=1;i<=tsz;i++)par[i][0]=link[i];
		for(int j=1;j<L;j++)for(int i=1;i<=tsz;i++)par[i][j]=par[par[i][j-1]][j-1];
	}
	int GetLo(int node,int ln){
		for(int i=L-1;~i;i--)if(len[par[node][i]]>ln)node=par[node][i];
		if(len[node]<=ln)return len[node];
		else return len[par[node][0]];
	}
}FW,BW;
char s[N],t[N];
int pal[N],lmx[N],rmx[N];
int fwn[N],bwn[N];
void Solve(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	FW.init();
	BW.init();
	for(int i=1;i<=n;i++){
		fwn[i]=FW.Expand(s[i]);
	}
	for(int i=n;i>=1;i--){
		bwn[i]=BW.Expand(s[i]);
	}
	FW.Build();
	BW.Build();
	int ans=0,L=0,R=0;
	for(int i=0,j=n+1;i<j;i++,j--){
		int now=i*2+BW.GetLo(bwn[i+1],j-i-1);
		if(ans<now){
			ans=now;
			L=now-i;
			R=i;
		}
		now=i*2+FW.GetLo(fwn[j-1],j-i-1);
		if(ans<now){
			ans=now;
			L=i;
			R=now-i;
		}
		if(s[i+1]!=s[j-1])break;
	}
	for(int i=1;i<=L;i++)printf("%c",s[i]);
	for(int i=n-R+1;i<=n;i++)printf("%c",s[i]);
	printf("\n");
	/*int m=0;
	t[++m]='$';
	for(int i=1;i<=n;i++)t[++m]=s[i],t[++m]='$';
	t[m+1]=0;
	for(int i=1,l=0,r=0;i<=m;i++){
		int k=1;
		if(i<=r)k=min(pal[l+(r-i)],r-i+1);
		while(k<i && t[i-k]==t[i+k])k++;
		if(i+k-1>r)l=i-k+1,r=i+k-1;
	}
	for(int i=1;i<=n;i++)lmx[i]=rmx[i]=1;
	for(int i=1;i<=n;i++){
		int len=pal[i*2];
		ckmx(lmx[i-len/2],len);
		ckmx(rmx[i+len/2],len);
	}
	for(int i=1;i<n;i++){
		int len=pal[i*2+1];
		ckmx(lmx[i-len/2+1],len);
		ckmx(rmx[i+len/2],len);
	}
	for(int i=1;i<=n;i++)*/
}
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		Solve();
	}
	return 0;
}