// author: xay5421
// created: Tue Aug 31 22:57:41 2021
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
typedef long long LL;
int n,m;
vector<LL>p; // x-1 | x
struct node1{
	int t;
	LL x,y;
	void in(){
		static char opt[20];
		scanf("%s",opt);
		if(opt[0]=='b'){
			t=1;
		}else{
			t=2;
		}
		scanf("%lld%lld",&x,&y);
		if(t==1){
			p.push_back(x);
			p.push_back(y+1);
		}
	}
}q[50005];
struct ufs{
	const int n;
	vector<int>fa;
	ufs(int n):n(n),fa(n){for(int i=0;i<n;++i)fa[i]=i;}
	void reset(){for(int i=0;i<n;++i)fa[i]=i;}
	int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
	int mer(int k1,int k2){
		k1=fd(k1),k2=fd(k2);
		if(k1==k2)return 0;
		fa[k1]=k2;
		return 1;
	}
	bool chk(int k1,int k2){
		k1=fd(k1),k2=fd(k2);
		return k1==k2;
	}
};
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	rep(i,1,m)q[i].in();
	p.push_back(0),p.push_back(1LL<<n); // [)
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	per(i,SZ(p)-2,0){
		// [p[i],p[i+1])
		if(p[i]+1==p[i+1])continue;
		int diff=63-__builtin_clzll(p[i]^(p[i+1]-1));
		LL mid=((p[i]>>diff)+1)<<diff;
		if(p[i]<=mid&&mid<p[i+1]){
			p.push_back(mid);
		}
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	vector<vector<int> >e(SZ(p)-1,vector<int>());
	rep(bit,0,n-1){
		int j=0;
		rep(i,0,SZ(p)-2){
			LL pos=p[i]>>bit&1?p[i]:((p[i]>>bit)+1)<<bit;
			if(p[i]<=pos&&pos<p[i+1]){
				while(j<=SZ(p)-2&&pos-(1LL<<bit)>=p[j+1])++j;
				if(j<=SZ(p)-2&&i!=j)e[i].push_back(j),e[j].push_back(i);
			}
		}
		j=0;
		rep(i,0,SZ(p)-2){
			//LL pos=~(p[i+1]-1)>>bit&1?p[i+1]-1:((p[i+1]-1)>>(bit+1))<<(bit+1);
			LL pos=~(p[i])>>bit&1?p[i]:((p[i]>>bit)+1)<<bit;
			if(p[i]<=pos&&pos<p[i+1]){
				while(j<=SZ(p)-2&&pos+(1LL<<bit)>=p[j+1])++j;
				if(j<=SZ(p)-2&&i!=j)e[i].push_back(j),e[j].push_back(i);
			}
		}
	}
	vector<int>ban(SZ(p)-1);
	rep(i,1,m){
		int t=q[i].t;
		LL x=q[i].x,y=q[i].y;
		if(t==1){
			ban[upper_bound(p.begin(),p.end(),x)-p.begin()-1]=1;
			ban[upper_bound(p.begin(),p.end(),y)-p.begin()-1]=1;
		}
	}
	ufs o(SZ(p)-1);
	rep(i,0,SZ(p)-2)if(!ban[i])for(auto x:e[i])if(!ban[x])o.mer(i,x);
	vector<int>ans;
	per(i,m,1){
		int t=q[i].t;
		LL x=q[i].x,y=q[i].y;
		int k1=upper_bound(p.begin(),p.end(),x)-p.begin()-1;
		int k2=upper_bound(p.begin(),p.end(),y)-p.begin()-1;
		if(t==1){
			ban[k1]=ban[k2]=0;
			for(auto x:e[k1])if(!ban[x])o.mer(k1,x);
			for(auto x:e[k2])if(!ban[x])o.mer(k2,x);
		}else{
			ans.push_back(o.chk(k1,k2));
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto x:ans)printf("%d\n",x);
	return 0;
}