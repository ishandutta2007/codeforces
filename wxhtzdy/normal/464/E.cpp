#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
const int N=100050;
const int M=100*N;
const int B=33333;
const int mod1=998244353;
const int mod2=1e9+7;
int n,m,a,b,ls[M],rs[M],tsz,f[2],prv[N];
ll st[M],pw[N],p[N];
vector<pii> E[N];
bool was[N];
void Build(int&c,int ss,int se){
	c=++tsz;
	if(ss==se){st[c]=pw[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	st[c]=(st[ls[c]]+st[rs[c]])%mod2;
}
int WalkLeft(int c,int p,int ss,int se,int qi){
	if(se<qi||st[c]==st[p])return -1;
	if(ss==se)return ss;
	int mid=ss+se>>1;
	int ans=WalkLeft(ls[c],ls[p],ss,mid,qi);
	if(ans!=-1)return ans;
	else return WalkLeft(rs[c],rs[p],mid+1,se,qi);
}
int WalkRight(int c,int p,int ss,int se){
	if(st[c]==st[p])return 2;
	if(ss==se)return st[c]==0?0:1;
	int mid=ss+se>>1;
	if(st[rs[c]]==st[rs[p]])return WalkRight(ls[c],ls[p],ss,mid);
	else return WalkRight(rs[c],rs[p],mid+1,se);
}
void Set(int&c,int p,int ss,int se,int qi){
	c=++tsz;ls[c]=ls[p];rs[c]=rs[p];st[c]=st[p];
	if(ss==se){st[c]+=pw[ss];return;}
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[c],ls[p],ss,mid,qi);
	else Set(rs[c],rs[p],mid+1,se,qi);
	st[c]=(st[ls[c]]+st[rs[c]])%mod2;
}
void Update(int&c,int p,int r,int ss,int se,int qs,int qe){
	c=++tsz;
	int mid=ss+se>>1;
	if(qs<=ss&&mid<=qe)ls[c]=ls[r];
	else if(qs>mid||qe<ss)ls[c]=ls[p];
	else Update(ls[c],ls[p],ls[r],ss,mid,qs,qe);
	if(qs<=mid+1&&se<=qe)rs[c]=rs[r];
	else if(qs>se||qe<mid+1)rs[c]=rs[p];
	else Update(rs[c],rs[p],rs[r],mid+1,se,qs,qe);
	st[c]=(st[ls[c]]+st[rs[c]])%mod2;
}
ll Walk(int c,int ss,int se){
	if(ss==se){return st[c]>0?p[ss]:0LL;}
	int mid=ss+se>>1;
	return (Walk(ls[c],ss,mid)+Walk(rs[c],mid+1,se))%mod2;
}
void Debug(int c,int ss,int se){
	if(ss==0&&se==0)printf("%lld\n",st[c]);
	if(ss==se)return;
	int mid=ss+se>>1;
	Debug(ls[c],ss,mid);
	Debug(rs[c],mid+1,se);
}
vector<int> path;
void rec(int u){
	if(u!=a)rec(prv[u]);
	path.pb(u);
}
struct Node{
	int u,root,prv;
	Node(int _u=0,int _root=0,int _prv=0):u(_u),root(_root),prv(_prv){}
	bool operator < (const Node& x) const{
		return !WalkRight(root,x.root,0,N-1);
		//return Walk(root,0,N-1)<Walk(x.root,0,N-1);
	}
};
int main(){
	scanf("%i%i",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%i%i%i",&u,&v,&w);
		E[u].pb({v,w});
		E[v].pb({u,w});
	}
	Build(f[0],0,N-1);
	pw[0]=1;p[0]=1;
	for(int i=1;i<N;i++){
		pw[i]=(pw[i-1]*B)%mod2;
		p[i]=(p[i-1]*2)%mod2;
	}
	Build(f[1],0,N-1);
	scanf("%i%i",&a,&b);
	multiset<Node> s;
	s.insert(Node(a,f[0],1));
	//printf(":::%lld v %lld\n",st[f[0]],pw[2]);
	//printf("%d\n",WalkLeft(f[0],f[1],0,N-1,0));
	while(!s.empty()){
		auto it=s.begin();
		int u=(*it).u,root=(*it).root,pp=(*it).prv;
		s.erase(it);
		if(prv[u])continue;
		prv[u]=pp;
		/*if(u==2){
			printf("sada sam u 2\n");
			Debug(root,0,N-1);
		}*/
		if(u==b){
			//printf(":: %lld  %d\n",st[root],prv[u]);
			printf("%lld\n",Walk(root,0,N-1));
			rec(b);
			printf("%d\n",path.size());
			for(int i=0;i<path.size();i++)printf("%d ",path[i]);
			/*Debug(root,0,N-1);
			Debug(f[1],0,N-1);*/
			return 0;
		}
		for(auto e:E[u]){
			int v=e.fi;
			int w=e.se;
			//if(u==2&&v==3)printf("magija prelaz:\n");
			int pos=WalkLeft(root,f[1],0,N-1,w);
			//printf(":from:%d    to:%d    pos:%d\n\n\n",u,v,pos);
			int r,nr;
			Set(r,root,0,N-1,pos);
			if(w==pos)nr=r;
			else Update(nr,r,f[0],0,N-1,w,pos-1);
			s.insert(Node(v,nr,u));
		}
	}
	printf("-1");
	return 0;
}
/*
4 4
1 4 2
1 2 0
2 3 0
3 4 0
1 1
*/