#include<bits/stdc++.h>
#define ll long long
#define N 100005

int n,m;
char s[N];

int pre[26][N],nxt[26][N],lst[26];

inline int f(int L,int R);

int G[N];
inline int g(int x){
	if(!x)
		return 0;
	if(~G[x])
		return G[x];
	int tmp=g(pre[s[x]-'a'][x-1])^f(pre[s[x]-'a'][x-1]+1,x-1);
	G[x]=tmp;
	return tmp;
}

#define B 6662333
struct node{
	ll id;
	int val,nxt;
}e[N<<6];
int hd[B],_hd;
inline int fnd(ll x){
	int u=x%B;
	for(int i=hd[u];i;i=e[i].nxt)
		if(e[i].id==x)
			return e[i].val;
	return -1;
}
inline void ins(ll x,int val){
	int u=x%B;
	e[++_hd]=(node){x,val,hd[u]};
	hd[u]=_hd;
}

#define num(x,y) (1ll*((x)-1)*n+(y))
inline int f(int L,int R){
	if(L>R)
		return 0;
	int tmp=fnd(num(L,R));
	if(~tmp)
		return tmp;
	ll sg=0;
	for(int i=0;i<26;i++)
		if(pre[i][R]>=L&&nxt[i][L]<=R)
			sg|=1<<(f(L,nxt[i][L]-1)^g(nxt[i][L])^g(pre[i][R])^f(pre[i][R]+1,R));
	int res=0;
	while((sg>>res)&1)
		res++;
	ins(num(L,R),res);
	return res;
}

int main(){
	scanf("%s%d",s+1,&m);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		lst[s[i]-'a']=i;
		for(int j=0;j<26;j++)
			pre[j][i]=lst[j];
	}
	for(int i=0;i<26;i++)
		lst[i]=n+1;
	for(int i=n;i;i--){
		lst[s[i]-'a']=i;
		for(int j=0;j<26;j++)
			nxt[j][i]=lst[j];
	}
	memset(G,-1,sizeof(G));
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		puts(f(l,r)?"Alice":"Bob");
	}
}