#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 100005

int n,k,a[N];

int cnt[N];
inline ll cal(int L,int R){
	static int l=1,r=0;
	static ll res=0;
	while(r<R){
		res+=cnt[a[++r]];
		cnt[a[r]]++;
	}
	while(l>L){
		res+=cnt[a[--l]];
		cnt[a[l]]++;
	}
	while(r>R){
		cnt[a[r]]--;
		res-=cnt[a[r--]];
	}
	while(l<L){
		cnt[a[l]]--;
		res-=cnt[a[l++]];
	}
	return res;
}

ll f[N],g[N];
inline void sol(int L,int R,int l,int r){
	if(L>R)
		return;
	int mid=(L+R)>>1,vm=-1;
	ll tmp=inf;
	for(int i=l;i<=r&&i<mid;i++)
		if(vm<0||g[i]+cal(i+1,mid)<tmp)
			tmp=g[i]+cal(i+1,mid),vm=i;
	f[mid]=std::min(f[mid],tmp);
	if(L==R)
		return;
	sol(L,mid-1,l,vm),sol(mid+1,R,vm,r);
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	while(k--){
		std::swap(f,g);
		memset(f,0x3f,sizeof(f));
		sol(1,n,0,n-1);
		f[0]=0;
	}
	printf("%lld\n",f[n]);
}