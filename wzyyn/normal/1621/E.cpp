#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int n,m;
int a[N];
vector<int> e[N];

int findP(int s,long long v){
	int l=1,r=n,ans=n+1;
	while (l<=r){
		int mid=(l+r)/2;
		if (v<=1ll*a[mid]*s)
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int mn[N*4],tg[N*4];
void build(int k,int l,int r){
	tg[k]=0;
	if (l==r){
		mn[k]=n+1-l;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	mn[k]=min(mn[k*2],mn[k*2+1]);
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		tg[k]+=v;
		mn[k]+=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	mn[k]=min(mn[k*2],mn[k*2+1])+tg[k];
}
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	build(1,1,n+1);
	for (int i=1;i<=m;i++){
		e[i].resize(0);
		int x,y;
		long long sum=0;
		scanf("%d",&x);
		for (;x--;){
			scanf("%d",&y);
			e[i].push_back(y);
			sum+=y;
		}
		int p=findP(e[i].size(),sum);
		change(1,1,n+1,1,p,-1);
	}
	for (int i=1;i<=m;i++){
		long long sum=0;
		for (auto j:e[i]) sum+=j;
		int p=findP(e[i].size(),sum);
		change(1,1,n+1,1,p,1);
		for (auto j:e[i]){
			int np=findP(e[i].size()-1,sum-j);
			change(1,1,n+1,1,np,-1);
			putchar(mn[1]>=0?'1':'0');
			change(1,1,n+1,1,np,1);
		}
		change(1,1,n+1,1,p,-1);
	}
	puts("");
	
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}