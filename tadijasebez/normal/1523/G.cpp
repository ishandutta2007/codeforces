#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const int N=50050;
const int M=100050;
const int H=M*17;
const int inf=1e9+7;
/*int root[N],tsz,ls[H],rs[H],mn[H],tsz;
void Upd(int p,int&c,int ss,int se,int qi,int idx){
	c=++tsz;ls[c]=ls[p];rs[c]=rs[p];mn[c]=min(mn[p],idx);
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Upd(ls[p],ls[c],ss,mid,qi,idx);
	else Upd(rs[p],rs[c],mid+1,se,qi,idx);
}
int Get(int c,int ss,int se,int qs,int qe){
	if(qs>qe||qs>se||ss>qe)return inf;
	if(qs<=ss&&qe>=se)return mn[c];
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}*/
int l[M],r[M];
vector<int> ids[M];
const int S=1000;
vector<int> block[M],pref[M];
void MakePref(int B){
	pref[B].clear();
	pref[B].pb(inf);
	for(int i:block[B]){
		pref[B].pb(min(i,pref[B].back()));
	}
}
int LL[M],RR[M],ord[M],srt[M],bl[M],n,m;
void Erase(int B,int i){
	int j;
	for(j=0;block[B][j]!=i;j++);
	for(int z=j+1;z<block[B].size();z++){
		block[B][z-1]=block[B][z];
	}
	block[B].pop_back();
	MakePref(B);
}
int GetBlock(int B,int r){
	int top=block[B].size(),bot=0;
	while(top>bot){
		int mid=top+bot>>1;
		if(::r[block[B][mid]]<=r){
			bot=mid+1;
		}else top=mid;
	}
	return pref[B][top];
}
int Get(int l,int r){
	int ans=inf;
	for(int b=0;b<=m/S;b++){
		if(block[b].empty())continue;
		if(RR[b]<l||LL[b]>r)continue;
		if(LL[b]>=l&&RR[b]<=r){
			ckmn(ans,GetBlock(b,r));
		}else{
			for(int i:block[b]){
				if(::l[i]>=l&&::r[i]<=r){
					ckmn(ans,i);
				}
			}
		}
	}
	return ans;
}
vector<int> all[N];
int main(){
	//mn[0]=inf;
	rd(n,m);
	for(int i=1;i<=m;i++){
		rd(l[i],r[i]);
		ids[l[i]].pb(i);
		srt[i]=i;
		all[r[i]-l[i]+1].pb(i);
	}
	sort(srt+1,srt+1+m,[&](int i,int j){
		return r[i]<r[j];
	});
	int cnt=0;
	for(int j=0;j<=m;j++)LL[j]=inf;
	for(int i=1;i<=n;i++){
		//root[i]=root[i-1];
		for(int j:ids[i]){
			//Upd(root[i],root[i],1,n,l[j],j);
			ord[j]=cnt++;
			bl[j]=ord[j]/S;
			ckmn(LL[bl[j]],i);
			ckmx(RR[bl[j]],i);
		}
	}
	for(int j=1;j<=m;j++){
		int i=srt[j];
		block[bl[i]].pb(i);
	}
	for(int j=0;j<m;j++){
		if(block[j].empty())break;
		MakePref(j);
	}
	for(int x=1;x<=n;x++){
		set<pair<int,pii>> cand;
		cand.insert({Get(1,n),{1,n}});
		int ans=0;
		while(cand.size()){
			auto ca=*cand.begin();
			if(ca.first==inf)break;
			cand.erase(cand.begin());
			//printf("%i (%i %i)\n",ca.first,ca.second.first,ca.second.second);
			ans+=r[ca.first]-l[ca.first]+1;
			int o=Get(ca.second.first,l[ca.first]-1);
			if(o!=inf)cand.insert({o,{ca.second.first,l[ca.first]-1}});
			o=Get(r[ca.first]+1,ca.second.second);
			if(o!=inf)cand.insert({o,{r[ca.first]+1,ca.second.second}});
		}
		printf("%i\n",ans);
		for(int i:all[x]){
			Erase(bl[i],i);
		}
	}
	return 0;
}