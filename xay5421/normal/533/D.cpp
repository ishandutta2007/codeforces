#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=100005,INF=0X3F3F3F3F;
int n,ans,a[N],d[N],f[N],g[N];
void gen(int*f){
	vector<pair<int,LL> >st;
	rep(i,1,n){
		while(!st.empty()&&st.back().second<a[i])st.pop_back();
		f[i]=st.empty()?0:st.back().first;
		pair<int,LL>cur={i,d[i]*2LL+a[f[i]]};
		while(!st.empty()&&cur.second>=st.back().second)st.pop_back();
		st.pb(cur);
	}
}
void rev(){
	int maxx=a[n+1];
	reverse(a,a+n+2);
	rep(i,0,n+1)a[i]=maxx-a[i];
	reverse(d+1,d+n+1);
}
int main(){
	scanf("%d",&n);
	rep(i,0,n+1)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&d[i]);
	d[0]=d[n+1]=INF;
	ans=a[n+1]-a[0];
	gen(f);
	rev();
	gen(g);
	reverse(g+1,g+1+n);
	rep(i,1,n)g[i]=n+1-g[i];
	rev();
	rep(i,1,n){
		if(a[g[i]]-a[f[i]]<=d[i]*2)ans=0;
		ans=min(ans,a[g[i]]-a[f[i]]);
	}
	rep(i,1,n){
		if(f[i]==0&&a[g[i]]-a[i]<d[i]*2){
			ans=min(ans,a[i]-a[0]);
		}
		if(g[i]==n+1&&a[i]-a[f[i]]<d[i]*2){
			ans=min(ans,a[n+1]-a[i]);
		}
	}
	vector<int>good_f,good_g;
	rep(i,1,n){
		if(a[i]-a[f[i]]<d[i]*2)good_f.pb(i);
		if(a[g[i]]-a[i]<d[i]*2)good_g.pb(i);
	}
	map<LL,int>S;
	auto push=[&](LL x,int y){
		auto it=S.lower_bound(x);
		if(it!=S.end()&&it->second>=y)return;
		if(it->first==x){
			it->second=y;
		}else{
			it=S.insert({x,y}).first;
		}
		while(it!=S.begin()&&prev(it)->second<=y)S.erase(prev(it));
	};
	auto ask=[&](LL low)->LL{ // x>=low max(y)
		auto it=S.lower_bound(low);
		if(it==S.end())return -1;
		return it->second;
	};
	auto it=good_f.begin();
	for(auto&j:good_g){
		while(it!=good_f.end()&&*it<j){
			int i=*it;
			push(d[i]*2LL+a[f[i]],a[i]);
			++it;
		}
		int res=ask(a[g[j]]-d[j]*2LL);
		if(res!=-1){
			ans=min(ans,a[j]-res);
		}
	}
	printf("%.4f\n",ans*0.5);
	return 0;
}