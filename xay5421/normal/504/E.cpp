#include<bits/stdc++.h>
#define EB emplace_back
#define PB push_back
#define D(...) fprintf(stderr,__VA_ARGS__)
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=300005,B=31,P=998244853;
int n,m,h[2][N],pw[N],dep[N],sz[N],fa[N],son[N],ind,tin[N],bel[N];
char s[N],_s[N];
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
int getha(int o,int k1,int k2,int k3=-1){
	assert(k1<=k2);
	if(k3==-1)k3=k2-k1+1;
	if(o==0)k2=k1+k3-1;
	else k1=k2-k3+1;
	if(o==0)return(h[o][k2]-1LL*h[o][k1-1]*pw[k2-k1+1]%P+P)%P;
	else return(h[o][k1]-1LL*h[o][k2+1]*pw[k2-k1+1]%P+P)%P;
}
void dfs1(int k1,int k2){
	dep[k1]=dep[k2]+1,fa[k1]=k2,sz[k1]=1;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		dfs1(to[i],k1);
		sz[k1]+=sz[to[i]];
		if(sz[to[i]]>sz[son[k1]])son[k1]=to[i];
	}
}
void dfs2(int k1){
	tin[k1]=++ind,s[ind]=_s[k1];
	if(son[k1]){
		bel[son[k1]]=bel[k1];
		dfs2(son[k1]);
	}
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=fa[k1]&&to[i]!=son[k1]){
		bel[to[i]]=to[i];
		dfs2(to[i]);
	}
}
vector<tuple<int,int,int> >getlu(int k1,int k2){
	vector<tuple<int,int,int> >r[2];
	int o1=1,o2=0;
	while(bel[k1]!=bel[k2]){
		if(dep[bel[k1]]<dep[bel[k2]])swap(k1,k2),swap(o1,o2);
		r[o1].EB(tin[bel[k1]],tin[k1],o1);
		k1=fa[bel[k1]];
	}
	if(dep[k1]<dep[k2])swap(k1,k2),swap(o1,o2);
	r[o1].EB(tin[k2],tin[k1],o1);
	while(SZ(r[0])){
		r[1].PB(r[0].back());
		r[0].pop_back();
	}
	return r[1];
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	pw[0]=1;
	rep(i,1,N-1)pw[i]=1LL*pw[i-1]*B%P;
	scanf("%d%s",&n,_s+1);
	rep(i,2,n){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
	}
	dfs1(1,0);
	bel[1]=1,dfs2(1);
	rep(i,1,n)h[0][i]=(1LL*h[0][i-1]*B+s[i]-'a'+1)%P;
	per(i,n,1)h[1][i]=(1LL*h[1][i+1]*B+s[i]-'a'+1)%P;
	scanf("%d",&m);
	rep(_,1,m){
		D(">>> %d\n",_);
		int k1,k2,k3,k4;
		scanf("%d%d%d%d",&k1,&k2,&k3,&k4);
		auto r1=getlu(k1,k2);
		auto r2=getlu(k3,k4);
		int i=0,j=0;
		int ans=0;
		auto pop=[&](tuple<int,int,int>&k1,int k2){
			if(get<2>(k1)==0)get<0>(k1)+=k2;
			else get<1>(k1)-=k2;
		};
		while(i<SZ(r1)&&j<SZ(r2)){
			int len=min(get<1>(r1[i])-get<0>(r1[i])+1,get<1>(r2[j])-get<0>(r2[j])+1);
			if(getha(get<2>(r1[i]),get<0>(r1[i]),get<1>(r1[i]),len)==getha(get<2>(r2[j]),get<0>(r2[j]),get<1>(r2[j]),len)){
				pop(r1[i],len);
				pop(r2[j],len);
				ans+=len;
			}else{
				int L=1,R=len,res=0;
				while(L<=R){
					int mid=(L+R)>>1;
					if(getha(get<2>(r1[i]),get<0>(r1[i]),get<1>(r1[i]),mid)==getha(get<2>(r2[j]),get<0>(r2[j]),get<1>(r2[j]),mid)){
						res=mid,L=mid+1;
					}else R=mid-1;
				}
				ans+=res;
				break;
			}
			if(get<0>(r1[i])>get<1>(r1[i]))++i;
			if(get<0>(r2[j])>get<1>(r2[j]))++j;
		}
		printf("%d\n",ans);
	}
	return 0;
}