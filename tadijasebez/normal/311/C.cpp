#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
const int M=10050;
ll mn[M],h;
int ord[M],tmp[M],que[M],k,n,m;
bool was[M];
ll a[N];int c[N];
stack<int> stk[M];
struct cmp{bool operator()(int i,int j){return c[i]>c[j]||(c[i]==c[j]&&i<j);}};
set<int,cmp> pts;
bool in[N];
void Cns(int ost){
	while(stk[ost].size()&&a[stk[ost].top()]>=mn[ost]){
		int i=stk[ost].top();
		stk[ost].pop();
		pts.insert(i);
		in[i]=1;
	}
}
void Upd(ll x){
	int i=1,j=1,xb=0,xz=0;
	for(int i=0;i<k;i++)was[i]=0;
	for(;i<=k||j<=xb;){
		int u;
		if(i>k||(j<=xb&&mn[que[j]]<mn[ord[i]]))u=que[j++];
		else u=ord[i++];
		if(was[u])continue;
		was[u]=1;tmp[++xz]=u;
		int v=(u+x)%k;
		if(mn[v]>mn[u]+x){
			mn[v]=mn[u]+x;
			Cns(v);
			que[++xb]=v;
		}
	}
	assert(xz==k);
	for(int i=1;i<=k;i++)ord[i]=tmp[i];
}
int main(){
	scanf("%lld %i %i %i",&h,&n,&m,&k);
	for(int i=1;i<k;i++)mn[i]=h;
	for(int i=1;i<=k;i++)ord[i]=i-1;
	vector<int> ord;
	for(int i=1;i<=n;i++)scanf("%lld %i",&a[i],&c[i]),a[i]--,ord.pb(i);
	sort(ord.begin(),ord.end(),[&](int i,int j){return a[i]<a[j];});
	for(int i:ord)stk[a[i]%k].push(i);
	Cns(0);
	while(m--){
		int t;scanf("%i",&t);
		if(t==1){
			ll x;scanf("%lld",&x);
			Upd(x);
		}else if(t==2){
			int x,y;scanf("%i %i",&x,&y);
			if(in[x])pts.erase(x);
			c[x]-=y;
			if(in[x])pts.insert(x);
		}else{
			if(pts.empty())printf("0\n");
			else{
				int i=*pts.begin();
				printf("%i\n",c[i]);
				pts.erase(i);c[i]=0;in[i]=0;
			}
		}
	}
	return 0;
}