#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int maxn=1000007<<2;
int val[maxn],mxp[maxn],mnp[maxn];
struct tree{
	int mx,mn;
	int left,right;
}tree[maxn];

void pushup(int idx){
	tree[idx].mx=max(tree[idx<<1].mx,tree[idx<<1|1].mx);
	tree[idx].mn=min(tree[idx<<1].mn,tree[idx<<1|1].mn);
}

void build_tree(int num,int l,int r){
	tree[num].left=l;
	tree[num].right=r;
	if (l==r){
		tree[num].mx=tree[num].mn=val[l];
		return;
	}
	int mid=(l+r)>>1;
	build_tree(num<<1,l,mid);
	build_tree(num<<1|1,mid+1,r);
	pushup(num);
}

int query_mx(int num,int l,int r){
	if (l<=tree[num].left&&tree[num].right<=r){
		return tree[num].mx;
	}
	int mid=(tree[num].left+tree[num].right)>>1;
	if (l>mid){
		return query_mx(num<<1|1,l,r);
	}
	else{
		if (r<=mid){
			return query_mx(num<<1,l,r);
		}
		else{
			return max(query_mx(num<<1,l,r),query_mx(num<<1|1,l,r));
		}
	}
}

int query_mn(int num,int l,int r){
	if (l<=tree[num].left&&tree[num].right<=r){
		return tree[num].mn;
	}
	int mid=(tree[num].left+tree[num].right)>>1;
	if (l>mid){
		return query_mn(num<<1|1,l,r);
	}
	else{
		if (r<=mid){
			return query_mn(num<<1,l,r);
		}
		else{
			return min(query_mn(num<<1,l,r),query_mn(num<<1|1,l,r));
		}
	}
}

int n,x; 

int main(){
	scanf("%d%d",&n,&x);
	memset(mnp,0,sizeof(mnp));
	for (int i=1;i<=n;++i){
		scanf("%d",&val[i]);
		if (!mnp[val[i]]){
			mnp[val[i]]=i;
		}
		mxp[val[i]]=i;
	}
	build_tree(1,1,n);
	int i=x;
	long long ans=0;
	while(i>1){
		if (mnp[i]&&query_mx(1,1,mxp[i])>i){
			break;
		}
		i--;
	}
	ans=x-i+1;
	for (int j=1;j<x;++j){
		if (mnp[j]&&query_mn(1,mnp[j],n)<j){
			break;
		}
		i=max(i,j+1);
		if (mnp[j]){
			i=max(i,query_mx(1,1,mxp[j]));
		}
		ans+=x-i+1;
	}
	printf("%lld\n",ans);
	return 0;
}