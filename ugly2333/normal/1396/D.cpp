//CF1396D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 2222;
const int T = 4444;
const int MO = 1e9+7;
int mul(int x,int y){
	return (LL)x*y%MO;
}
int n,k,l,x[N],y[N],z[N],nx,cx[N],ny,cy[N],py[N],le[N],ri[N];
map<int,int> M;
map<int,int>::iterator it;
vector<int> v[N]; 
set<int> S[N];
set<int>::iterator it1;
LL ss,ans;
int a[N],t[T],w[T],fl[T],fr[T];
void build(int k=1,int l=1,int r=ny-1){
	w[k]=-1;
	fl[k]=a[l],fr[k]=a[r];
	if(l==r){
		t[k]=mul(a[l],cy[l]);
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	t[k]=t[k<<1]+t[k<<1|1];
	if(t[k]>=MO)
		t[k]-=MO;
}
void modify(int L,int v,int k=1,int l=1,int r=ny-1){
	if(r<L||fl[k]<=v)
		return;
	if(L<=l&&v<=fr[k]){
		w[k]=v;
		fl[k]=v,fr[k]=v;
		t[k]=mul(v,py[r]-py[l-1]);
		return;
	}
	int h=l+r>>1;
	if(w[k]>=0){
		w[k<<1]=w[k],w[k<<1|1]=w[k];
		fl[k<<1]=w[k],fr[k<<1]=w[k],fl[k<<1|1]=w[k],fr[k<<1|1]=w[k];
		t[k<<1]=mul(w[k],py[h]-py[l-1]),t[k<<1|1]=mul(w[k],py[r]-py[h]);
		w[k]=-1;
	}
	modify(L,v,k<<1,l,h);
	modify(L,v,k<<1|1,h+1,r);
	fl[k]=fl[k<<1],fr[k]=fr[k<<1|1];
	t[k]=t[k<<1]+t[k<<1|1];
	if(t[k]>=MO)
		t[k]-=MO;
}
int main()
{
	int i,j,o,e;
	scanf("%d%d%d",&n,&k,&l);
	for(i=1;i<=n;i=i+1)
		scanf("%d%d%d",x+i,y+i,z+i);
	M[-1]=1,M[l]=1;
	for(i=1;i<=n;i=i+1)
		M[x[i]]=1;
	nx=-1;
	for(it=M.begin();it!=M.end();it++)
		(*it).second=++nx,cx[nx]=(*it).first;
	for(i=1;i<=n;i=i+1)
		x[i]=M[x[i]];
	M.clear();
	for(i=nx;i>=1;i=i-1)
		cx[i]-=cx[i-1];
	M[-1]=1,M[l]=1;
	for(i=1;i<=n;i=i+1)
		M[y[i]]=1;
	ny=-1;
	for(it=M.begin();it!=M.end();it++)
		(*it).second=++ny,py[ny]=(*it).first;
	for(i=1;i<=ny;i=i+1)
		cy[i]=py[i]-py[i-1];
	for(i=1;i<=n;i=i+1)
		y[i]=M[y[i]];
	M.clear();
	for(i=1;i<=n;i=i+1)
		v[x[i]].push_back(i);
	for(j=1;j<=nx;j=j+1){
		ss=0;
		for(i=1;i<=k;i=i+1)
			S[i].clear(),S[i].insert(0),S[i].insert(ny);
		for(i=j;i<nx;i=i+1){
			for(o=0;o<v[i].size();o=o+1){
				e=v[i][o];
				it1=S[z[e]].lower_bound(y[e]);
				if((*it1)==y[e])
					le[e]=-1,ri[e]=-1;
				else{
					ri[e]=(*it1);
					it1--;
					le[e]=(*it1);
				}
				S[z[e]].insert(y[e]);
			}
		}
		for(i=1;i<ny;i=i+1)
			a[i]=0;
		for(i=1;i<=k;i=i+1){
			o=0;
			for(it1=S[i].begin();it1!=S[i].end();it1++){
				if((*it1)==0)
					continue;
				a[o+1]=max(a[o+1],(*it1));
				o=(*it1);
			}
		}
		for(i=2;i<ny;i=i+1)
			a[i]=max(a[i],a[i-1]);
		for(i=1;i<ny;i=i+1)
			a[i]=l-py[a[i]];
		build();
		for(i=nx;i>j;){
			ss+=mul(t[1],cx[i]),ss%=MO;
			i--;
			for(o=v[i].size();o--;){
				e=v[i][o];
				if(le[e]!=-1)
					modify(le[e]+1,l-py[ri[e]]);
			}
		}
		ans+=mul(ss,cx[j]),ans%=MO;
	}
	cout<<ans;
	return 0;
}