#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=200007;
const int INF=1e12;
int tree[maxn<<2],lz[maxn<<2];
int n,s[maxn],ans[maxn];

void pushup(int num){
	tree[num]=min(tree[num<<1],tree[num<<1|1]);
}

void pushdown(int num){
	if (lz[num]){
		tree[num<<1]+=lz[num];
		tree[num<<1|1]+=lz[num];
		lz[num<<1]+=lz[num];
		lz[num<<1|1]+=lz[num];
		lz[num]=0;
	}
}

void build(int num,int l,int r){
	if (l==r){
		tree[num]=s[l];
		return;
	}
	int md=(l+r)>>1;
	build(num<<1,l,md);
	build(num<<1|1,md+1,r);
	pushup(num);
}

void update(int num,int l,int r,int L,int R,int val){
	if (L<=l&&r<=R){
		tree[num]+=val,lz[num]+=val;
		return;
	}
	pushdown(num);
	int md=(l+r)>>1;
	if (L<=md) update(num<<1,l,md,L,R,val);
	if (R>md) update(num<<1|1,md+1,r,L,R,val);
	pushup(num);
}

int query(int num,int l,int r){
	if (l==r){
		return l;
	}
	pushdown(num);
	int md=(l+r)>>1;
	if (tree[num<<1|1]){
		query(num<<1,l,md);
	}
	else{
		query(num<<1|1,md+1,r);
	}
}
#undef int
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>s[i];
	}
	build(1,1,n);
	for (int i=1;i<=n;++i){
		int idx=query(1,1,n);
		ans[idx]=i;
		if (idx<n){
			update(1,1,n,idx+1,n,-i);
		}
		update(1,1,n,idx,idx,INF);
	}
	for (int i=1;i<=n;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}