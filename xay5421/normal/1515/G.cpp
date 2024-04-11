// author: xay5421
// created: Sun May  2 23:13:57 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,m,st[N],top,cnt,bel[N],ind,low[N],dfn[N];
LL dep[N],gg[N],ww[N];
bool ins[N],vis[N];
int pp,lnk[N],nxt[N],to[N],we[N];
void ae(int k1,int k2,int k3){to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;}
LL gcd(LL a,LL b){
	if(!a)return b;
	while(a^=b^=a^=b%=a,a);
	return b;
}
void tarjan(int k1){
	low[k1]=dfn[k1]=++ind,st[++top]=k1,ins[k1]=1,vis[k1]=1;
	for(int i=lnk[k1];i;i=nxt[i]){
		if(!dfn[to[i]]){
			dep[to[i]]=dep[k1]+we[i];
			tarjan(to[i]),low[k1]=min(low[k1],low[to[i]]);
		}
		else if(ins[to[i]]){
			low[k1]=min(low[k1],dfn[to[i]]);
		}
	}
	if(low[k1]==dfn[k1]){
		++cnt;
		vector<int>v;
		do{
			ins[st[top]]=0;
			bel[st[top]]=cnt;
			v.push_back(st[top]);
		}while(st[top--]!=k1);
		for(auto x:v){
			for(int i=lnk[x];i;i=nxt[i])if(bel[to[i]]==cnt){
				ww[cnt]=gcd(ww[cnt],abs(dep[x]-dep[to[i]]+we[i]));
			}
		}
	}
	vis[k1]=0;
}
int main(){
	rd(n),rd(m);
	rep(i,1,m){
		int k1,k2,k3;
		rd(k1),rd(k2),rd(k3);
		ae(k1,k2,k3);
	}
	rep(i,1,n)if(!dfn[i]){
		tarjan(i);
	}
	int Q;
	rd(Q);
	while(Q--){
		int v;
		LL s,t;
		rd(v),rd(s),rd(t);
		if((t-s)%gcd(t,ww[bel[v]])==0)puts("YES");else puts("NO");
	}
	return 0;
}