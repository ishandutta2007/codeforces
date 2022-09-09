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

const int N=105;
int a[N],b[N];
vector<vector<int>> ans;
pii Get(int x,int n){
	int l=x,r=x;
	while(l>1&&a[l-1]==a[l]-1)l--;
	while(r<n&&a[r+1]==a[r]+1)r++;
	return {l,r};
}
void Do(int a,int b,int c,int d,int n){
	ans.pb({});
	if(a>0)ans.back().pb(a);
	ans.back().pb(b);
	ans.back().pb(c);
	if(d>0)ans.back().pb(d);
	for(int i=0;i<a;i++){
		::b[n-a+1+i]=::a[1+i];
	}
	for(int i=0;i<b;i++){
		::b[n-a-b+1+i]=::a[a+1+i];
	}
	for(int i=0;i<c;i++){
		::b[n-a-b-c+1+i]=::a[a+b+1+i];
	}
	for(int i=0;i<d;i++){
		::b[n-a-b-c-d+1+i]=::a[a+b+c+1+i];
	}
	for(int i=1;i<=n;i++){
		::a[i]=::b[i];
		//printf("%i ",::a[i]);
	}
	//printf("\n");
}
void Op(int x,int y,int n){
	pii X=Get(x,n);
	pii Y=Get(y,n);
	Do(X.first-1,Y.first-X.first,Y.second-Y.first+1,n-Y.second,n);
	/*ans.pb(vector<int>());
	if(x!=1)ans.back().pb(x-1);
	ans.back().pb(y-x);
	ans.back().pb(1);
	if(n!=y)ans.back().pb(n-y);
	for(int i=1;i<x;i++){
		b[i+n-x+1]=a[i];
	}
	for(int i=x;i<y;i++){
		b[i-x+1+n-y+1]=a[i];
	}
	b[n-y+1]=a[y];
	for(int i=y+1;i<=n;i++){
		b[i-y]=a[i];
	}
	printf("OP %i %i\n",x,y);
	for(int i=1;i<=n;i++){
		a[i]=b[i];
		printf("%i ",a[i]);
	}
	printf("\n");*/
}
int main(){
	int n=ri();
	ra(a,n);
	while(1){
		int x,y;
		bool ok=0;
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++){
				if(a[j]==i)y=j;
				if(a[j]==i+1)x=j;
			}
			if(x<y){ok=1;break;}
		}
		if(!ok)break;
		Op(x,y,n);
	}
	printf("%i\n",ans.size());
	for(auto o:ans){
		printf("%i ",o.size());
		for(int i:o)printf("%i ",i);
		printf("\n");
	}
	return 0;
}