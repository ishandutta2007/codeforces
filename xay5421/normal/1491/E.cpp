// author: xay5421
// created: Mon Mar  1 00:27:22 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,f[100],sz[N],fa[N],st[N],top;
bool ban[N];
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void calc(int k1,int k2){
	sz[k1]=1,st[++top]=k1,fa[k1]=k2;
	for(int i=lnk[k1];i;i=nxt[i])if(!ban[to[i]]&&to[i]!=k2)calc(to[i],k1),sz[k1]+=sz[to[i]];
}
bool dfs(int k1,int id){
	if(id<=1)return 1;
	top=0;
	calc(k1,0);
	int t=-1;
	rep(i,1,top)if(sz[st[i]]==f[id-1]||sz[st[i]]==f[id-2]){
		t=st[i];
		break;
	}
	if(t!=-1){
		ban[fa[t]]=1;
		int tmp=sz[t],fafa=fa[t];
		if(tmp==f[id-1]){
			if(!dfs(t,id-1))return 0;
		}else{
			if(!dfs(t,id-2))return 0;
		}
		ban[fafa]=0;
		ban[t]=1;
		if(tmp==f[id-1]){
			if(!dfs(fafa,id-2))return 0;
		}else{
			if(!dfs(fafa,id-1))return 0;
		}
		ban[t]=0;
		return 1;
	}
	return 0;
}
int main(){
	f[0]=f[1]=1;
	rep(i,2,30)f[i]=f[i-1]+f[i-2];
	rd(n);
	rep(i,1,n-1){
		int k1,k2;
		rd(k1),rd(k2);
		ae(k1,k2),ae(k2,k1);
	}
	int id=-1;
	rep(i,1,30)if(f[i]==n){
		id=i;
	}
	if(id==-1)puts("NO");else{
		if(dfs(1,id)){
			puts("YES");
		}else puts("NO");
	}
	return 0;
}