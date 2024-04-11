// author: xay5421
// created: Fri Jun 18 13:48:57 2021
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
const LL INFLL=0X3F3F3F3F3F3F3F3F;
int n,m,B,G;
void exgcd(int a,int b,int&x,int&y){
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int inv(int v,int mod){
	int x,y;
	exgcd(v,mod,x,y);
	int res=(x%mod+mod)%mod;
	assert(1LL*res*v%mod==1);
	return res;
}
LL sol(vector<int>boy,vector<int>girl){
	vector<int>a(boy);
	a.insert(a.end(),girl.begin(),girl.end());
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	if(SZ(a)==n){
		vector<int>bin(m);
		for(int x:boy)if(x<m)++bin[x];
		for(int x:girl)if(x<m)++bin[x];
		per(i,m-1,0)if(bin[i]==1)return i;
		return -1;
	}
	int invm=inv(m,n);
	vector<array<int,3> >vec;
	int _=0;
	for(int&x:a)vec.push_back({int(1LL*x*invm%n),x,_++});
	sort(vec.begin(),vec.end());
	vector<int>go(_);
	rep(i,0,SZ(vec)-1){
		go[vec[i][2]]=vec[(i+1)%SZ(vec)][2];
	}
	priority_queue<pair<int,int> >q;
	vector<LL>dis(_,1e18);
	rep(i,0,_-1)dis[i]=a[i],q.emplace(-dis[i],i);
	vector<bool>vis(_);
	LL res=0;
	while(!q.empty()){
		int k1=q.top().second;
		if(vis[k1])q.pop();
		vis[k1]=1;
		LL cost=1LL*m*((1LL*a[go[k1]]*invm%n-1LL*a[k1]*invm%n+n)%n);
		//D("cost=%lld\n",cost);
		res=max(res,dis[k1]+(cost==0?1LL*m*(n-1):cost-m));
		if(dis[k1]+cost<dis[go[k1]]){
			dis[go[k1]]=dis[k1]+cost;
			q.emplace(-dis[go[k1]],go[k1]);
		}
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d",&B);
	vector<int>boy(B);
	rep(i,0,B-1)scanf("%d",&boy[i]);
	scanf("%d",&G);
	vector<int>girl(G);
	rep(i,0,G-1)scanf("%d",&girl[i]);
	if(n<m)swap(n,m),swap(B,G),swap(boy,girl);
	int gys=__gcd(n,m);
	if(gys>B+G)puts("-1"),exit(0);
	vector<vector<int> >boys(gys),girls(gys);
	n/=gys,m/=gys;
	rep(i,0,B-1)boys[boy[i]%gys].push_back(boy[i]/gys);
	rep(i,0,G-1)girls[girl[i]%gys].push_back(girl[i]/gys);
	rep(i,0,gys-1)if(boys[i].empty()&&girls[i].empty())puts("-1"),exit(0);
	LL ans=0;
	rep(i,0,gys-1){
		ans=max(ans,sol(boys[i],girls[i])*gys+i);
	}
	printf("%lld\n",ans);
	return 0;
}