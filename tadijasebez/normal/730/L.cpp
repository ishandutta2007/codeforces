#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=400050;
const int mod=1e9+7;
int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
int sub(int x,int y){x-=y;return x<0?x+mod:x;}
int mul(int x,int y){return (ll)x*y%mod;}
char expr[N];
const int LOG=20;
int tsz,ls[N],rs[N],type[N],par[N][LOG],dep[N],val[N];//type: 0 number, 1 +, 2 *, 3 ()
int L[N],R[N],my_node[N],brup[N];
void DFS(int u,int p){
	dep[u]=dep[p]+1;
	par[u][0]=p;
	brup[u]=brup[p]+(type[u]==3);
	for(int i=1;i<LOG;i++)par[u][i]=par[par[u][i-1]][i-1];
	if(type[u]==0){
		val[u]=0;
		for(int i=L[u];i<=R[u];i++)val[u]=add(mul(10,val[u]),expr[i]-'0');
		//printf("%i %i\n",u,val[u]);
		return;
	}
	DFS(ls[u],u);
	L[u]=L[ls[u]];
	R[u]=R[ls[u]];
	if(type[u]!=3)DFS(rs[u],u),R[u]=R[rs[u]];
	if(type[u]==1)val[u]=add(val[ls[u]],val[rs[u]]);
	if(type[u]==2)val[u]=mul(val[ls[u]],val[rs[u]]);
	if(type[u]==3)val[u]=val[ls[u]];
	//if(type[u]==3)printf("() ");
	//else if(type[u]==2)printf("*  ");
	//else printf("+  ");
	//printf("%i %i\n",u,val[u]);
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=LOG-1;~i;i--)if(dep[par[u][i]]>=dep[v])u=par[u][i];
	for(int i=LOG-1;~i;i--)if(par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
int Climb(int u,int k){for(int i=0;i<LOG;i++)if(k>>i&1)u=par[u][i];return u;}
int l[N],r[N],ans[N],n;
namespace Pref{
	int pre[N],pw[N];
	void Build(){
		pw[0]=1;
		for(int i=1;i<=n;i++){
			int v=expr[i]-'0';
			if(expr[i]<'0'||expr[i]>'9')v=0;
			pre[i]=add(mul(pre[i-1],10),v);
			pw[i]=mul(pw[i-1],10);
		}
	}
	int EasyGet(int l,int r){
		/*int ans=0;
		for(int i=l;i<=r;i++){
			ans=add(mul(ans,10),expr[i]-'0');
		}
		return ans;*/
		return sub(pre[r],mul(pw[r-l+1],pre[l-1]));
	}
};
bool work[N];
vector<int> QL[N],QR[N];
int rqa[N],lqa[N];
struct SegmentTree{
	static const int M=2*N;
	int ls[M],rs[M],tsz,root;
	int lzy_add[M],lzy_mul[M],val[M];
	void Build(int&c,int ss,int se){
		c=++tsz;lzy_add[c]=0;lzy_mul[c]=1;
		if(ss==se){val[c]=0;return;}
		int mid=ss+se>>1;
		Build(ls[c],ss,mid);
		Build(rs[c],mid+1,se);
	}
	void Build(){Build(root,1,n);}
	void upd(int c,int ad,int ml){
		val[c]=mul(val[c],ml);
		val[c]=add(val[c],ad);
		lzy_add[c]=mul(lzy_add[c],ml);
		lzy_mul[c]=mul(lzy_mul[c],ml);
		lzy_add[c]=add(lzy_add[c],ad);
	}
	void push(int c){
		upd(ls[c],lzy_add[c],lzy_mul[c]);
		upd(rs[c],lzy_add[c],lzy_mul[c]);
		lzy_add[c]=0;
		lzy_mul[c]=1;
	}
	void Set(int c,int ss,int se,int qs,int qe,int ad,int ml){
		if(qs>qe||qs>se||ss>qe)return;
		if(qs<=ss&&qe>=se){upd(c,ad,ml);return;}
		int mid=ss+se>>1;
		push(c);
		Set(ls[c],ss,mid,qs,qe,ad,ml);
		Set(rs[c],mid+1,se,qs,qe,ad,ml);
	}
	void Add(int qs,int qe,int ad){Set(root,1,n,qs,qe,ad,1);}
	void Mul(int qs,int qe,int ml){Set(root,1,n,qs,qe,0,ml);}
	int Get(int c,int ss,int se,int qi){
		if(ss==se)return val[c];
		int mid=ss+se>>1;
		push(c);
		if(qi<=mid)return Get(ls[c],ss,mid,qi);
		else return Get(rs[c],mid+1,se,qi);
	}
	int Get(int qi){return Get(root,1,n,qi);}
	void Set1(int c,int ss,int se,int qi,int v){
		if(ss==se){val[c]=v;return;}
		int mid=ss+se>>1;
		push(c);
		if(qi<=mid)Set1(ls[c],ss,mid,qi,v);
		else Set1(rs[c],mid+1,se,qi,v);
	}
	void Set(int qi,int v){Set1(root,1,n,qi,v);}
}SGL,SGR;
void SolveQsOffline(int u){
	if(type[u]==0){//number
		for(int i=L[u];i<=R[u];i++){
			SGR.Set(i,Pref::EasyGet(L[u],i));
			SGL.Set(i,Pref::EasyGet(i,R[u]));
		}
	}else if(type[u]==1){//+
		SolveQsOffline(ls[u]);
		SolveQsOffline(rs[u]);
		SGL.Add(L[ls[u]],R[ls[u]],val[rs[u]]);
		SGR.Add(L[rs[u]],R[rs[u]],val[ls[u]]);
	}else if(type[u]==2){//*
		SolveQsOffline(ls[u]);
		SolveQsOffline(rs[u]);
		SGL.Mul(L[ls[u]],R[ls[u]],val[rs[u]]);
		SGR.Mul(L[rs[u]],R[rs[u]],val[ls[u]]);
	}else{//()
		SolveQsOffline(ls[u]);
	}
	for(int qi:QL[u]){
		//printf("Work L %i on %i\n",qi,u);
		if(type[my_node[l[qi]]]==0)lqa[qi]=SGL.Get(l[qi]);
		else lqa[qi]=SGL.Get(L[my_node[l[qi]]]);
	}
	for(int qi:QR[u]){
		//printf("Work R %i on %i\n",qi,u);
		if(type[my_node[r[qi]]]==0)rqa[qi]=SGR.Get(r[qi]);
		else rqa[qi]=SGR.Get(R[my_node[r[qi]]]);
	}
	//printf("Node %i\n",u);
	//for(int i=1;i<=n;i++)printf("%i ",SGL.Get(i));printf("\n");
	//for(int i=1;i<=n;i++)printf("%i ",SGR.Get(i));printf("\n");
}
bool Bad(int u,int p){
	int br=brup[par[u][0]]-brup[p];
	return br>0;
}
int main(){
	scanf("%s",expr+1);
	n=strlen(expr+1);
	stack<int> nodes,pos;
	stack<char> ops;
	auto MakeMul=[&](){
		assert(ops.top()=='*');
		ops.pop();
		int b=nodes.top();
		nodes.pop();
		int a=nodes.top();
		nodes.pop();
		tsz++;
		type[tsz]=2;
		ls[tsz]=a;
		rs[tsz]=b;
		nodes.push(tsz);
	};
	auto MakePlus=[&](){
		assert(ops.top()=='+');
		ops.pop();
		int b=nodes.top();
		nodes.pop();
		int a=nodes.top();
		nodes.pop();
		tsz++;
		type[tsz]=1;
		ls[tsz]=a;
		rs[tsz]=b;
		nodes.push(tsz);
	};
	auto NewNumber=[&](int i){
		tsz++;
		type[tsz]=0;
		L[tsz]=R[tsz]=i;
		nodes.push(tsz);
	};
	for(int i=1;i<=n;i++){
		if(expr[i]=='('){
			ops.push('(');
			pos.push(i);
		}else if(expr[i]=='+'){
			while(ops.size()&&ops.top()=='*')MakeMul();
			ops.push('+');
		}else if(expr[i]=='*'){
			ops.push('*');
		}else if(expr[i]==')'){
			while(ops.size()&&ops.top()=='*')MakeMul();
			while(ops.size()&&ops.top()=='+')MakePlus();
			assert(ops.top()=='(');
			ops.pop();
			int a=nodes.top();
			nodes.pop();
			tsz++;
			type[tsz]=3;
			ls[tsz]=a;
			nodes.push(tsz);
			my_node[i]=my_node[pos.top()]=tsz;
			pos.pop();
		}else{
			if(i==1||expr[i-1]<'0'||expr[i-1]>'9')NewNumber(i);
			R[nodes.top()]=i;
			my_node[i]=nodes.top();
		}
	}
	while(ops.size()&&ops.top()=='*')MakeMul();
	while(ops.size()&&ops.top()=='+')MakePlus();
	assert(ops.empty());
	assert(nodes.size()==1);
	int root=nodes.top();
	DFS(root,0);
	Pref::Build();
	int q;
	scanf("%i",&q);
	for(int i=1;i<=q;i++){
		scanf("%i %i",&l[i],&r[i]);
		if(expr[l[i]]=='+'||expr[l[i]]=='*'||expr[r[i]]=='+'||expr[r[i]]=='*'){
			ans[i]=-1;
			continue;
		}
		if(expr[l[i]]==')'||expr[r[i]]=='('){
			ans[i]=-1;
			continue;
		}
		int lnd=my_node[l[i]];
		int rnd=my_node[r[i]];
		if(lnd==rnd){
			if(type[lnd]==0)ans[i]=Pref::EasyGet(l[i],r[i]);
			else{
				assert(type[lnd]==3);
				ans[i]=val[lnd];
			}
			continue;
		}
		int lca=LCA(lnd,rnd);
		if(lca==lnd||lca==rnd){
			ans[i]=-1;
		}else if(Bad(lnd,lca)||Bad(rnd,lca)){
			ans[i]=-1;
		}else{
			int lup=Climb(lnd,dep[lnd]-dep[lca]-1);
			int rup=Climb(rnd,dep[rnd]-dep[lca]-1);
			//printf("Up %i %i %i\n",i,lup,rup);
			work[i]=true;
			QL[lup].push_back(i);
			QR[rup].push_back(i);
		}
	}
	SGL.Build();
	SGR.Build();
	SolveQsOffline(root);
	for(int i=1;i<=q;i++){
		if(work[i]){
			int lnd=my_node[l[i]];
			int rnd=my_node[r[i]];
			int lca=LCA(lnd,rnd);
			if(type[lca]==1){//+
				ans[i]=add(lqa[i],rqa[i]);
			}else{//*
				ans[i]=mul(lqa[i],rqa[i]);
			}
			//printf("Q %i: %i %i\n",i,lqa[i],rqa[i]);
		}
	}
	for(int i=1;i<=q;i++)printf("%i\n",ans[i]);
	return 0;
}