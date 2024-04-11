#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
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
const int N=300050;
const int M=4*N;
int root,mx[M],lzy[M];
void Add(int c,int ss,int se,int qs,int qe,int f){
	if(qs>qe||qs>se||ss>qe)return;
	if(qs<=ss&&qe>=se){mx[c]+=f;lzy[c]+=f;return;}
	int mid=ss+se>>1;
	Add(c<<1,ss,mid,qs,qe,f);
	Add(c<<1|1,mid+1,se,qs,qe,f);
	mx[c]=max(mx[c<<1],mx[c<<1|1])+lzy[c];
}
int Walk(int c,int ss,int se,int k){
	if(ss==se)return mx[c]>=k?ss:ss-1;
	int mid=ss+se>>1;
	if(mx[c<<1|1]+lzy[c]>=k)return Walk(c<<1|1,mid+1,se,k-lzy[c]);
	else return Walk(c<<1,ss,mid,k-lzy[c]);
}
int Get(int c,int ss,int se,int qi){
	if(ss==se)return mx[c];
	int mid=ss+se>>1;
	if(qi<=mid)return Get(c<<1,ss,mid,qi)+lzy[c];
	else return Get(c<<1|1,mid+1,se,qi)+lzy[c];
}
int a[N],ans[N];
vector<pii> Qs[N];
int main(){
	int n,q;
	rd(n,q);
	for(int i=1;i<=n;i++){
		scanf("%i",&a[i]);
	}
	for(int i=1;i<=q;i++){
		int x,y;rd(x,y);
		int l=x+1,r=n-y;
		Qs[r].pb({l,i});
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=i){
			int j=Walk(1,1,n,i-a[i]);
			j=min(j,i);
			Add(1,1,n,1,j,1);
		}
		for(auto qu:Qs[i])ans[qu.second]=Get(1,1,n,qu.first);
	}
	for(int i=1;i<=q;i++)printf("%i\n",ans[i]);
	return 0;
}