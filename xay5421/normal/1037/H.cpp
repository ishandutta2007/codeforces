// author: xay5421
// created: Thu Oct 28 23:13:08 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005;
int n,Q;
char s[N*2],t[N*2];
struct SAM{
	int cnt,lst,fa[N*2],ch[N*2][26],len[N*2],pos[N*2];
	vector<int>e[N*2];
	SAM(){cnt=lst=1;}
	void ps(int c,int pos0){
		int p=lst,np=lst=++cnt; len[np]=len[p]+1,pos[np]=pos0;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(!p){fa[np]=1;return;}
		int q=ch[p][c];
		if(len[p]+1==len[q]){fa[np]=q;return;}
		int nq=++cnt; len[nq]=len[p]+1;
		memcpy(ch[nq],ch[q],sizeof(ch[nq]));
		fa[nq]=fa[q],fa[q]=fa[np]=nq;
		for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
	}
	const static int M=N*80;
	int lc[M],rc[M],ind;
	int rt[N*2];
	void mdf(int&k1,int k2,int k3,int k4){
		k1=++ind;
		if(k2==k3)return;
		int mid=(k2+k3)>>1;
		if(k4<=mid)mdf(lc[k1],k2,mid,k4);
		else mdf(rc[k1],mid+1,k3,k4);
	}
	int mer(int k1,int k,int k2,int k3){
		if(!k1||!k)return k1+k;
		int mid=(k2+k3)>>1;
		int u=++ind;
		lc[u]=mer(lc[k1],lc[k],k2,mid);
		rc[u]=mer(rc[k1],rc[k],mid+1,k3);
		return u;
	}
	int ask(int k1,int k2,int k3,int k4,int k5){
		if(k2>k3||k2>k5||k3<k4||!k1)return 0;
		if(k4<=k2&&k3<=k5)return 1;
		int mid=(k2+k3)>>1;
		return ask(lc[k1],k2,mid,k4,k5)||ask(rc[k1],mid+1,k3,k4,k5);
	}
	void dfs(int k1){
		if(pos[k1])mdf(rt[k1],1,cnt,pos[k1]);
		for(auto x:e[k1]){
			dfs(x);
			rt[k1]=mer(rt[k1],rt[x],1,cnt);
		}
	}
	void bud(){
		rep(i,2,cnt){
			e[fa[i]].pb(i);
		}
		dfs(1);
	}
}A;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%s",s+1),n=strlen(s+1);
	rep(i,1,n){
		A.ps(s[i]-'a',i);
	}
	A.bud();
	scanf("%d",&Q);
	while(Q--){
		int l,r;
		scanf("%d%d%s",&l,&r,s+1);
		int len=strlen(s+1);
		int i=1;
		int p=1;
		for(;i<=len+1;++i){
			t[i]=0;
			rep(j,i==len+1?0:s[i]-'a'+1,25){
				int np=A.ch[p][j];
				if(np&&A.ask(A.rt[np],1,A.cnt,l+i-1,r)){
					t[i]=j+'a';
					break;
				}
			}
			if(i==len+1)break;
			p=A.ch[p][s[i]-'a'];
			if(!p||!A.ask(A.rt[p],1,A.cnt,l+i-1,r)){
				break;
			}
		}
		while(i>=1&&!t[i])--i;
		if(i<1)puts("-1");
		else{
			rep(j,1,i-1)putchar(s[j]);
			putchar(t[i]);
			puts("");
		}
	}
	return 0;
}