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
using LL=long long;
int T;
LL res;
struct node{
	map<int,int>f;
	LL real(){
		LL y=1;
		for(auto&x:f){
			rep(_,0,x.second-1){
				y*=x.first;
			}
		}
		return y;
	}
	void ps(int x){
		rep(i,2,x/i)if(x%i==0){
			int t=0;
			while(x%i==0)t+=1,x/=i;
			f[i]+=t;
		}
		if(x>1)f[x]+=1;
	}
	void read(){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ps(x),ps(y),ps(z);
	}
	void dfs_d(map<int,int>::iterator i,LL n){
		if(n<=0)return;
		if(i==f.end()){++res;return;}
		rep(_,0,i->second){
			if(_)n/=i->first;
			if(!n)break;
			dfs_d(next(i),n);
		}
	}
	int get_d(LL n){
		res=0;
		dfs_d(f.begin(),n);
		return res;
	}
};
LL power(LL a,LL b){
	LL c=1;
	while(b--)c*=a;
	return c;
}
LL work(const node&a,const node&b,LL m){
	auto i=a.f.begin();
	auto j=b.f.begin();
	vector<pair<int,LL> >v;
	while(i!=a.f.end()||j!=b.f.end()){
		if(j==b.f.end()||(i!=a.f.end()&&i->first<j->first)){
			v.eb(i->first,1);
			++i;
		}else if(i==a.f.end()||i->first>j->first){
			++j;
		}
		else{
			if(i->second>j->second){
				v.eb(i->first,power(i->first,j->second));
			}
			++i,++j;
		}
	}
	LL res=0;
	function<void(int,LL)>dfs=[&](int step,LL m){
		if(m==0)return;
		if(step>=SZ(v)){
			res+=m;
			return;
		}
		dfs(step+1,m);
		dfs(step+1,-m/get<1>(v[step])/get<0>(v[step]));
	};
	dfs(0,m);
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		node n,m,s;
		n.read(),m.read(),s.read();
		LL n1=n.real(),m1=m.real(),s1=s.real();
		/*{
			LL ans=0;
			rep(i,1,m1){
				ans+=s1*2%__gcd<LL>(n1,i)==0;
			}
			D("ans1=%lld\n",ans);
			rep(i,1,n1){
				ans+=s1*2%i==0;
			}
			D("brute:%lld\n",ans);
		}*/
		s.f[2]+=1;
		LL ans=work(n,s,m1);
		//D("ans2=%lld\n",ans);
		ans+=s.get_d(n1);
		printf("%lld\n",ans);
	}
	return 0;
}