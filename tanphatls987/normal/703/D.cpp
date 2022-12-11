#include <bits/stdc++.h>

using namespace std;

#define X first 
#define Y second 
#define FOR(i,L,R) for(auto i=(L);i<=(R);i++)
#define REP(i,L,R) for(auto i=(L);i<(R);i++)

typedef pair<int,int> ii;
typedef long long ll;

const int MOD=1e9+7;
const int N=1e6+10;

int n,m;
int ans[N];
int a[N];
int pxor[N];
vector<ii> v[N];
map <int,int> ma;
struct segtree{
	int b[N<<2];
	void update(int node,int L,int R,int idx,int val){
		if (L>idx||R<idx) return;
		if (L==R){
			b[node]^=val;
			return;
		}
		update(node*2,L,(L+R)/2,idx,val);
		update(node*2+1,(L+R)/2+1,R,idx,val);
		b[node]=b[node*2]^b[node*2+1];
	}
	int get(int node,int L,int R,int l,int r){
		if (L>r||R<l) return 0;
		if (l<=L&&R<=r) return b[node];
		return get(node*2,L,(L+R)/2,l,r)^get(node*2+1,(L+R)/2+1,R,l,r);
	}
}mseg;
void prepare(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) pxor[i]=pxor[i-1]^a[i];
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[y].push_back(ii(x,i));
	}
}
void solve(){
	for(int i=1;i<=n;i++){
		int last=ma[a[i]];
		if (last) mseg.update(1,1,n,last,a[last]);
		mseg.update(1,1,n,i,a[i]);
		ma[a[i]]=i;
		for(auto j:v[i]){
			// cout<<pxor[i]<<" "<<pxor[j.X-1]<<" "<<mseg.get(1,1,n,j.X,i)<<'\n';
			ans[j.Y]=pxor[i]^pxor[j.X-1]^mseg.get(1,1,n,j.X,i);
		}
		// cout<<i<<"=>"<<a[i]<<" "<<last<<'\n';
		// for(int j=1;j<=n;j++) cout<<mseg.get(1,1,n,j,j)<<" \n"[j==n];
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
}
int main(){
	prepare();
	solve();
}