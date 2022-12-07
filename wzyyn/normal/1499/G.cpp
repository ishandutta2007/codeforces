#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=400005;
const int mo=998244353;
int n1,n2,m,Q,vP=1,vid,nd,ans;

int pl[N],pr[N],id[N],q[N];
int ls[N],rs[N],sz[N],S[N][2];
int idx[N],vS[N],rev[N],fa[N];

void Rever(int x){
	rev[x]^=1;
	swap(ls[x],rs[x]);
	if (sz[x]&1);
	else swap(S[x][0],S[x][1]);
}
void pushdown(int x){
	if (!rev[x]) return;
	if (ls[x]) Rever(ls[x]);
	if (rs[x]) Rever(rs[x]);
	rev[x]=0;
}
void Construct(int x,int c){
	pushdown(x);
	if (ls[x]) Construct(ls[x],c);
	if ((c+1+sz[ls[x]])%2==0) q[++*q]=idx[x];
	if (rs[x]) Construct(rs[x],c+1+sz[ls[x]]);
} 
void pushup(int x){
	S[x][0]=S[ls[x]][0];
	S[x][1]=S[ls[x]][1];
	if (sz[ls[x]]&1){
		S[x][1]=(S[x][1]+vS[x])%mo;
		S[x][0]=(S[x][0]+S[rs[x]][0])%mo;
		S[x][1]=(S[x][1]+S[rs[x]][1])%mo;
	}
	else{
		S[x][0]=(S[x][0]+vS[x])%mo;
		S[x][1]=(S[x][1]+S[rs[x]][0])%mo;
		S[x][0]=(S[x][0]+S[rs[x]][1])%mo;
	}
	sz[x]=sz[ls[x]]+1+sz[rs[x]];
}
void Insert(int x,int y){
	int np=++nd;
	if (id[x]&&id[y]&&id[x]==id[y]){
		int p=id[x]; id[x]=id[y]=0;
		ans=(ans+mo-S[p][1])%mo;
		if (pr[p]!=x){
			Rever(p);
			swap(pl[p],pr[p]);
		}
		ls[np]=p; fa[p]=1;
		vS[np]=vP=1ll*vP*2%mo;
		idx[np]=++vid;
		pushup(np);
		ans=(ans+S[np][1])%mo;
		return;
	}
	if (id[x]){
		int p=id[x]; id[x]=0;
		ans=(ans+mo-S[p][1])%mo;
		if (pr[p]!=x){
			Rever(p);
			swap(pl[p],pr[p]);
		}
		pl[np]=pl[p];
		ls[np]=p; fa[p]=1;
	}
	else
		pl[np]=x;
	if (id[y]){
		int p=id[y]; id[y]=0;
		ans=(ans+mo-S[p][1])%mo;
		if (pl[p]!=y){
			Rever(p);
			swap(pl[p],pr[p]);
		}
		pr[np]=pr[p];
		rs[np]=p; fa[p]=1;
	}
	else
		pr[np]=y;
	id[pl[np]]=np;
	id[pr[np]]=np;
	vS[np]=vP=1ll*vP*2%mo;
	idx[np]=++vid;
	pushup(np);
	//cout<<np<<' '<<ls[np]<<' '<<rs[np]<<' '<<sz[np]<<' '<<S[np][0]<<' '<<S[np][1]<<endl;
	ans=(ans+S[np][1])%mo;
}
void Construct(){
	*q=0;
	For(i,1,nd) if (!fa[i]) Construct(i,0);
	For(i,0,*q) printf("%d ",q[i]);
	puts("");
}
int main(){
	scanf("%d%d%d",&n1,&n2,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		Insert(x,y+n1);
	}
	scanf("%d",&Q);
	while (Q--){
		int tp;
		scanf("%d",&tp);
		if (tp==2) Construct();
		else{
			int x,y;
			scanf("%d%d",&x,&y);
			Insert(x,y+n1);
			printf("%d\n",ans);
		}
		fflush(stdout);
	}
}