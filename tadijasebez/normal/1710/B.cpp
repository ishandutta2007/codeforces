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

const int N=200050;
int x[N],p[N];
ll ans[N];

const int M=2*N*3;
int ls[M],rs[M],tsz,root1,root2,root3;
ll mx[M];

void cl(){
	for(int i=1;i<=tsz;i++){
		ls[i]=rs[i]=0;
		mx[i]=0;
	}
	root1=root2=root3=0;
	tsz=0;
}

void Build(int&c,int ss,int se,ll*arr){
	c=++tsz;
	if(ss==se){
		mx[c]=arr[ss];
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid,arr);
	Build(rs[c],mid+1,se,arr);
	mx[c]=max(mx[ls[c]],mx[rs[c]]);
}
const ll inf=1e18;
ll Get(int c,int ss,int se,int qs,int qe){
	if(qs>se||ss>qe||qs>se)return -inf;
	if(qs<=ss&&qe>=se)return mx[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
ll seg[N],seg1[N],seg2[N];
int ord[N],vals[N],qrd[N];

int main(){
	int t=ri();
	while(t--){
		int n,m;
		rd(n,m);
		ra(x,p,n);
		vector<array<int,3>> events;
		for(int i=1;i<=n;i++){
			events.push_back({x[i]-p[i],1,0});
			events.push_back({x[i],-2,0});
			events.push_back({x[i]+p[i],1,0});
			events.push_back({x[i],0,i});
			ans[i]=0;
		}
		sort(events.begin(),events.end());
		ll sum=0,last=0,balance=0;
		int osz=0;
		for(auto ev:events){
			int now=ev[0];
			sum+=balance*(now-last);
			if(ev[1]==0){
				ans[ev[2]]=sum;
				seg[++osz]=sum;
				ord[osz]=ev[2];
				qrd[ev[2]]=osz;
				vals[osz]=ev[0];
			}
			balance+=ev[1];
			last=now;
		}
		assert(osz==n);
		for(int i=1;i<=n;i++){
			seg1[i]=seg[i]-vals[i];
			seg2[i]=seg[i]+vals[i];
			//printf("%i ",vals[i]);
		}
		cl();
		Build(root1,1,n,seg1);
		Build(root2,1,n,seg2);
		Build(root3,1,n,seg);
		for(int i=1;i<=n;i++){
			int lb=lower_bound(vals+1,vals+1+n,x[i]-p[i]+1)-vals;
			int rb=upper_bound(vals+1,vals+1+n,x[i]+p[i]-1)-vals-1;
			assert(lb<=rb);
			int mb=qrd[i];
			//if(!(lb<=mb && mb<=rb)){
			//	printf("\n%i %i\n%i %i %i\n",x[i],x[i]+p[i]-1,lb,mb,rb);
			//}
			assert(lb<=mb && mb<=rb);
			bool ok=true;
			if(Get(root1,1,n,lb,mb)+x[i]-p[i]>m)ok=false;
			if(Get(root2,1,n,mb,rb)-x[i]-p[i]>m)ok=false;
			if(Get(root3,1,n,1,lb-1)>m)ok=false;
			if(Get(root3,1,n,rb+1,n)>m)ok=false;
			if(ok)printf("1");
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}