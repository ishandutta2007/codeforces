#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}

const int N=400050;
const int M=2*N;
int ls[M],rs[M],tsz,root,mx[M],lzy[M];
void Build(int&c,int ss,int se){
	c=++tsz;if(ss==se)return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Add(int c,int ss,int se,int qs,int qe,int f){
	if(qs>qe||qs>se||ss>qe)return;
	if(qs<=ss&&qe>=se){lzy[c]+=f;mx[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
}
int Get(int c,int ss,int se,int qs,int qe){
	if(qs<=ss&&qe>=se)return mx[c];
	int mid=ss+se>>1;
	if(qe<=mid)return Get(ls[c],ss,mid,qs,qe)+lzy[c];
	if(qs>mid)return Get(rs[c],mid+1,se,qs,qe)+lzy[c];
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe))+lzy[c];
}
int main(){
	int n,k,m;rd(n,k,m);
	set<pair<int,int>> has;
	multiset<int> mx;
	Build(root,1,n*2);
	for(int i=1;i<=n*2;i++)Add(root,1,n*2,i,i,i-n-1);
	while(m--){
		int x,y;rd(x,y);
		if(has.count({x,y})){
			has.erase({x,y});
			int fir=y+abs(x-k);
			mx.erase(mx.find(fir));
			Add(root,1,n*2,1,fir,-1);
		}else{
			has.insert({x,y});
			int fir=y+abs(x-k);
			mx.insert(fir);
			Add(root,1,n*2,1,fir,1);
		}
		if(mx.empty())printf("0\n");
		else printf("%i\n",max(0,Get(root,1,n*2,1,*mx.rbegin())));
	}
	return 0;
}