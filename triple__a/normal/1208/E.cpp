#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1000007;
const int INF=1e9+7;

//int tree[maxn<<2],lz[maxn<<2];
int n,w,l,a[maxn],tmp[maxn],rec[maxn],ans[maxn],sum[maxn];
/*
void pushup(int num){
	tree[num]=tree[num<<1]+tree[num<<1|1];
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
		tree[num]=lz[num]=0;
		return;
	}
	int md=(l+r)>>1;
	build(num<<1,l,md);
	build(num<<1|1,md+1,r);
}

void update(int num,int l,int r,int L,int R,int val){
	if (L>R) return;
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

int query(int num,int l,int r,int x){
	if (l==r){
		return tree[num];
	}
	pushdown(num);
	int md=(l+r)>>1;
	if (x<=md) return query(num<<1,l,md,x);
	if (x>md) return query(num<<1|1,md+1,r,x);
}
*/

void get_ans(int f[],int n,int k){
	deque<pair<int,int> > dq;
	dq.clear();
	for (int i=1;i<=n;++i){
		while (!dq.empty()){
			pair<int,int> u=dq.front();
			if (u.first<=f[i]){
				dq.pop_front();
			}
			else{
				break;
			}
		}
		dq.push_front(make_pair(f[i],i));
		while (!dq.empty()){
			pair<int,int> u=dq.back();
			if (u.second+k<=i){
				dq.pop_back();
			}
			else{
				if (i>=k){
					tmp[i-k+1]=u.first;
				}
				break;
			}
		}
		
	}
} 
#undef int
int main(){
	memset(ans,0,sizeof(ans));
	memset(sum,0,sizeof(sum));
	ios::sync_with_stdio(false);
	cin>>n>>w;
//	build(1,1,w);
	while (n--){
		cin>>l;
		for (int i=1;i<=l;++i){
			cin>>a[i];
		}
		if (2*l<=w){
			long long ret=0;
			for (int i=1;i<=l;++i){
				ret=max(ret,a[i]);
//				update(1,1,w,i,i,ret);
				ans[i]+=ret;
			}
//			update(1,1,w,l+1,w-l,ret);
			if (l+1<=w-l){
				sum[l+1]+=ret;
			}
			ret=0;
			for (int i=0;i<l;++i){
				ret=max(ret,a[l-i]);
//				update(1,1,w,w-i,w-i,ret);
				ans[w-i]+=ret;
			}
		}
		else{
			for (int i=1;i<=w-l;++i){
				rec[i]=0;
			}
			for (int i=1;i<=l;++i){
				rec[i+w-l]=a[i];
			}
			for (int i=1;i<=w-l;++i){
				rec[i+w]=0;
			}
			get_ans(rec,w+l,w-l+1);
			for (int i=1;i<=w;++i){
				//cout<<tmp[i]<<endl;
//				update(1,1,w,i,i,tmp[i]);
				ans[i]+=tmp[i];
			}
		}
	}
	long long cnt=0;
	for (int i=1;i<=w/2;++i){
		cnt+=sum[i];
		ans[i]+=cnt,ans[w+1-i]+=cnt;
	} 
	if (w%2){
		ans[(w+1)/2]+=cnt+sum[(w+1)/2];
	}
	for (int i=1;i<=w;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}