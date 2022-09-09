#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=300050;
/*int ls[N],rs[N],root,tsz,val[N],sz[N],pri[N];
mt19937 rng(time(0));
int nnd(int v){tsz++;val[tsz]=v;sz[tsz]=1;pri[tsz]=rng();return tsz;}
void pull(int c){sz[c]=sz[ls[c]]+1+sz[rs[c]];}
void rot_l(int &c){int a=rs[c],b=ls[a];ls[a]=c;rs[c]=b;pull(c);pull(a);c=a;}
void rot_r(int &c){int a=ls[c],b=rs[a];rs[a]=c;ls[c]=b;pull(c);pull(a);c=a;}
void ins(int &c,int v){
	if(!c){c=nnd(v);return;}
	if(val[c]<=v){
		ins(rs[c],v);
		if(pri[rs[c]]>pri[c])rot_l(c);
		else pull(c);
	}else{
		ins(ls[c],v);
		if(pri[ls[c]]>pri[c])rot_r(c);
		else pull(c);
	}
}
void del(int &c,int v){
	if(val[c]==v){
		if(!ls[c])c=rs[c];
		else if(!rs[c])c=ls[c];
		else if(pri[ls[c]]>pri[rs[c]])rot_r(c),del(rs[c],v),pull(c);
		else rot_l(c),del(ls[c],v),pull(c);
	}else if(val[c]<v)del(rs[c],v),pull(c);
	else del(ls[c],v),pull(c);
}
int get(int c,int v){
	if(!c)return 0;
	if(val[c]>=v)return get(ls[c],v)+1+sz[rs[c]];
	else return get(rs[c],v);
}
void print(int c){
	if(!c)return;
	print(ls[c]);
	printf("(%i %i) ",c,val[c]);
	print(rs[c]);
}*/
int bit[N];
void Add(int i,int f){for(i++;i;i-=i&-i)bit[i]+=f;}
int Get(int i){int ans=0;for(i++;i<N;i+=i&-i)ans+=bit[i];return ans;}
map<int,int> w[N];
int deg[N];
vector<int> E[N];
int main(){
	int n,p;
	scanf("%i %i",&n,&p);
	for(int i=1;i<=n;i++){
		int u,v;
		scanf("%i %i",&u,&v);
		if(!w[u][v]){
			E[u].pb(v);
			E[v].pb(u);
		}
		w[u][v]++;
		w[v][u]++;
		deg[u]++;
		deg[v]++;
	}
	for(int i=1;i<=n;i++)Add(deg[i],1);//ins(root,deg[i]);
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j:E[i]){
			Add(deg[j],-1);//del(root,deg[j]);
			deg[j]-=w[i][j];
			Add(deg[j],1);//ins(root,deg[j]);
		}
		ans+=Get(max(0,p-deg[i]));//ans+=get(root,p-deg[i]);
		if(deg[i]*2>=p)ans--;
		for(int j:E[i]){
			Add(deg[j],-1);//del(root,deg[j]);
			deg[j]+=w[i][j];
			Add(deg[j],1);//ins(root,deg[j]);
		}
	}
	ans/=2;
	printf("%lld\n",ans);
	return 0;
}