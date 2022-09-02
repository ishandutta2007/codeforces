// author: xay5421
// created: Tue Nov  2 08:51:53 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005;
int n,K;
vector<pair<int,int> >e[N],lims[N];
struct DS{
	int tag;
	map<int,int>S1,S2; // S1: S2:
	size_t size()const{return S1.size()+S2.size();}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q; // {r-l,l} {r-l-tag*2,l+tag}
	void reb(int x,int opt){
		if(opt==1){
			auto it=S2.upper_bound(x-tag*2);
			if(it!=S2.begin()){
				--it;
				q.emplace(x-it->first,it->first);
			}
		}else{
			auto it=S1.lower_bound(x+tag*2);
			if(it!=S1.end()){
				q.emplace(it->first-x,x);
			}
		}
	}
	void clip(int l,int r){ // S2[l] S1[r]
		if(S2.count(l)&&S1.count(r)){
			int t=S2[l]+S1[r];
			if(t>=0){
				S1[r]=t,S2.erase(l);
				reb(r,1);
			}else{
				S2[l]=t,S1.erase(r);
				reb(l,2);
			}
		}
	}
	void up(int l){
		while(!q.empty()){
			if(q.top().first-tag*2<=l*2){
				clip(q.top().second,q.top().second+q.top().first);
				q.pop();
			}else break;
		}
		tag+=l;
	}
	void add(int pos,int x){
		if(x>0){
			S1[pos+tag]+=x;
			reb(pos+tag,1);
		}else if(x<0){
			S2[pos-tag]+=x;
			reb(pos-tag,2);
		}
	}
	void operator+=(DS&k){
		for(auto x:k.S1){
			add(x.first-k.tag,x.second);
			D("! %d %d\n",x.first-k.tag,x.second);
		}
		for(auto x:k.S2){
			add(x.first+k.tag,x.second);
			D("! %d %d\n",x.first+k.tag,x.second);
		}
		k.S1.clear(),k.S2.clear();
	}
	int get(){
		auto i=S1.begin(),j=S2.begin();
		int cur=0,ans=0;
		while(i!=S1.end()||j!=S2.end()){
			if(i!=S1.end()&&(j==S2.end()||i->first-tag<j->first+tag)){
				cur+=(i++)->second;
			}else{
				cur+=(j++)->second;
			}
			ans=max(ans,cur);
		}
		return ans;
	}
	int ask(int x){
		auto i=S1.find(x+tag),j=S2.find(x-tag);
		return (i==S1.end()?0:i->second)+(j==S2.end()?0:j->second);
	}
}S[N];
void dfs1(int k1,int k2,int k3){
	for(auto x:e[k1])if(x.first!=k2){
		dfs1(x.first,k1,x.second);
		if(SZ(S[k1])<SZ(S[x.first]))swap(S[k1],S[x.first]);
		D("S[%d]+=S[%d]\n",k1,x.first);
		S[k1]+=S[x.first];
	}
	for(auto&x:lims[k1]){
		x.second-=max({0,-S[k1].ask(x.first),S[k1].ask(x.first+1)});
	}
	S[k1].up(1);
	D("k1=%d up=%d\n",k1,1);
	for(auto x:lims[k1])if(x.second>0){
		D("add pos=%d val=%d\n",x.first,x.second);
		S[k1].add(x.first,x.second);
		S[k1].add(x.first+1,-x.second);
	}
	S[k1].up(k3-1);
	D("k1=%d up=%d\n",k1,k3-1);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,2,n){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		w*=2;
		e[u].eb(v,w);
		e[v].eb(u,w);
	}
	scanf("%d",&K);
	rep(i,1,K){
		int d,f,p;
		scanf("%d%d%d",&d,&f,&p);
		d*=2;
		lims[p].eb(d,f);
	}
	dfs1(1,0,2);
	printf("%d\n",S[1].get());
	return 0;
}