#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
#define PII pair<int, int>
const int N = 3e5+10;
 
int n,q,sz,cnt=0,l,r,x[N],y[N],tr[N],last[N],ans[N];
map<PII, int> id;
vector<int> a[N];
vector<PII> b[N];
 
void add(int x,int val){
	for(;x<N;x+=x&-x)tr[x]+=val;
}
int sum(int x){
	int res = 0;
	for(;x;x-=x&-x)res+=tr[x];
	return res;
}
 
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&sz);
		rep(j,1,sz)scanf("%d%d",x+j,y+j);
		rep(j,1,sz){
			int dx=x[j%sz+1]-x[j],dy=y[j%sz+1]-y[j];
			int tmp = abs(__gcd(dx, dy));
			dx /= tmp, dy /= tmp;
			if(!id[{dx,dy}])id[{dx,dy}]=++cnt;
			a[i].PB(id[{dx,dy}]);
		}
	}
	scanf("%d",&q);
	rep(i,1,q)scanf("%d%d",&l,&r),b[r].PB({i,l});
	rep(i,1,n){
		for(int id:a[i]){
			if(last[id])add(last[id],-1);
			add(i,1);
			last[id] = i;
		}
		for(auto x:b[i])
			ans[x.first] = sum(i) - sum(x.second-1);
	}
	rep(i,1,q)printf("%d\n",ans[i]);
	return 0;
}