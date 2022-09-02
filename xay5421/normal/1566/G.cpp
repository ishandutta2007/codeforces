// author: xay5421
// created: Mon Sep 13 15:44:26 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline char getc(){static char buf[1<<20],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getc()))f^=!(c^45);x=(c&15);while(isdigit(c=getc()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
typedef long long LL;
const int N=100005;
int n,m,Q,id[N*4];
LL val[N*4];
set<pair<int,int> >S[N];
multiset<LL>glo;
vector<pair<int,int> >mn[N*4];
vector<pair<int,int> >operator+(const vector<pair<int,int> >&k1,const vector<pair<int,int> >&k2){
	vector<pair<int,int> >res;
	int i=0,j=0;
	while(i<SZ(k1)||j<SZ(k2)){
		if(i<SZ(k1)&&(j>=SZ(k2)||k1[i].first<k2[j].first)){
			bool flg=1;
			rep(t,0,j-1)if(k1[i].second==k2[t].second){flg=0;break;}
			if(flg){
				res.push_back(k1[i]);
				if(SZ(res)>2)break;
			}
			++i;
		}else{
			bool flg=1;
			rep(t,0,i-1)if(k2[j].second==k1[t].second){flg=0;break;}
			if(flg){
				res.push_back(k2[j]);
				if(SZ(res)>2)break;
			}
			++j;
		}
	}
	return res;
}
void upd_leaf(int k1,const set<pair<int,int> >&S){
	if(val[k1]!=-1){
		glo.erase(glo.find(val[k1]));
	}
	val[k1]=-1;
	mn[k1].clear();
	if(!S.empty()){
		auto it=S.begin();
		if(it!=S.end()){
			mn[k1].push_back(*it);
			++it;
			if(it!=S.end()){
				mn[k1].push_back(*it);
				++it;
				if(it!=S.end()){
					mn[k1].push_back(*it);
					val[k1]=(LL)mn[k1][0].first+mn[k1][1].first+mn[k1][2].first;
					glo.insert(val[k1]);
				}
			}
		}
	}
}
void upd(int k1){
	mn[k1]=mn[k1*2]+mn[k1*2+1];
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		id[k2]=k1;
		upd_leaf(k1,S[k2]);
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
map<pair<int,int>,int>mp;
void mdf(int k1,int u,int v,int w,int op){
	if(op==-1)S[u].erase(make_pair(w,v));
	else S[u].insert(make_pair(w,v));
	upd_leaf(k1,S[u]);
	k1>>=1;
	while(k1>0){
		upd(k1);
		k1>>=1;
	}
}
set<tuple<int,int,int> >es;
vector<pair<int,int> >res;
void ask(int k1,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		res=res+mn[k1];
		return;
	}
	int mid=(k2+k3)>>1;
	ask(k1*2,k2,mid,k4,k5),ask(k1*2+1,mid+1,k3,k4,k5);
}
void sol(){
	int w=get<0>(*es.begin()),u=get<1>(*es.begin()),v=get<2>(*es.begin());
	LL ans=!glo.empty()?*glo.begin():1e18;
	{
		auto it1=next(S[u].begin());
		auto it2=next(S[v].begin());
		if(it1!=S[u].end()&&it2!=S[v].end()){
			if(it1->second!=it2->second){
				ans=min(ans,(LL)it1->first+it2->first);
			}else{
				if(next(it1)!=S[u].end()){
					ans=min(ans,(LL)next(it1)->first+it2->first);
				}
				if(next(it2)!=S[v].end()){
					ans=min(ans,(LL)next(it2)->first+it1->first);
				}
			}
		}
	}
	{
		res.clear();
		if(1<=u-1)ask(1,1,n,1,u-1);
		if(u+1<=v-1)ask(1,1,n,u+1,v-1);
		if(v+1<=n)ask(1,1,n,v+1,n);
		rep(i,0,SZ(res)-1){
			if(res[i].second!=u&&res[i].second!=v){
				ans=min(ans,(LL)w+res[i].first);
			}
		}
	}
	pt(ans,'\n');
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	memset(val,-1,sizeof(val));
	rd(n),rd(m);
	rep(i,1,m){
		int k1,k2,k3;
		rd(k1),rd(k2),rd(k3);
		if(k1>k2)swap(k1,k2);
		es.insert(make_tuple(k3,k1,k2));
		mp[{k1,k2}]=k3;
		//D("k1=%d k2=%d k3=%d\n",k1,k2,k3);
		S[k1].insert({k3,k2});
		S[k2].insert({k3,k1});
	}
	bud(1,1,n);
	rd(Q);
	sol();
	while(Q--){
		int t,u,v;
		rd(t),rd(u),rd(v);
		if(u>v)swap(u,v);
		if(t==0){
			int w=mp[{u,v}];
			es.erase(make_tuple(w,u,v));
			mdf(id[u],u,v,w,-1);
			mdf(id[v],v,u,w,-1);
			mp.erase({u,v});
		}else{
			int w;
			rd(w);
			mp[{u,v}]=w;
			es.insert(make_tuple(w,u,v));
			mdf(id[u],u,v,w,1);
			mdf(id[v],v,u,w,1);
		}
		sol();
	}
	return 0;
}