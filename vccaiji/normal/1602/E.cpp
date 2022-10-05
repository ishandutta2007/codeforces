#include<bits/stdc++.h>
using namespace std;
int _,n,m,a[1100000],b[1100000],o[2100000],c[2100000],d[2100000],tot,minn[4100000],lazy[4100000],anss[2100000];
void pushdown(int p){
	minn[2*p]+=lazy[p];
	minn[2*p+1]+=lazy[p];
	lazy[2*p]+=lazy[p];
	lazy[2*p+1]+=lazy[p];
	lazy[p]=0;
}
void upd(int d,int x,int y,int l,int r,int p){
	if((x<=l)&&(y>=r)){
		minn[p]+=d;
		lazy[p]+=d;
		return;
	}
	pushdown(p);
	int md=(l+r)/2;
	if(x<=md) upd(d,x,y,l,md,2*p);
	if(y>=md+1) upd(d,x,y,md+1,r,2*p+1);
	minn[p]=min(minn[2*p],minn[2*p+1]);
}
void build(int l,int r,int p){
	if(l==r){
		minn[p]=l;
		lazy[p]=0;
		return;
	}
	lazy[p]=0;
	minn[p]=l;
	build(l,(l+r)/2,2*p);
	build((l+r)/2+1,r,2*p+1);
}
vector<int> aa[2100000];
int main(){
	scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=m;i++) scanf("%d",&b[i]);
		for(int i=1;i<=n;i++) c[i]=a[i];
		for(int i=n+1;i<=n+m;i++) c[i]=b[i-n];
		sort(c+1,c+n+m+1);
		tot=1;
		d[1]=c[1];
		for(int i=2;i<=n+m;i++){
			if(c[i]!=c[i-1]) d[++tot]=c[i];
		}
		for(int i=1;i<=n;i++){
			int l=1,r=tot;
			for(;l<r;){
				int md=(l+r)/2;
				if(d[md]<a[i]) l=md+1;
				else r=md;
			}
			a[i]=l;
		}
		for(int i=1;i<=m;i++){
			int l=1,r=tot;
			for(;l<r;){
				int md=(l+r)/2;
				if(d[md]<b[i]) l=md+1;
				else r=md;
			}
			b[i]=l;
		}
		for(int i=1;i<=tot;i++) o[i]=0;
		for(int i=0;i<=tot;i++)aa[i].clear();
		for(int i=1;i<=n;i++) aa[a[i]].push_back(i);
		long long ans=0;
		for(int i=n;i>=1;i--){
			for(int j=a[i]-1;j;j-=(j&(-j)))ans+=o[j];
			for(int j=a[i];j<=tot;j+=(j&(-j)))o[j]++;
		}
		build(0,n,1);
		for(int i=1;i<=tot;i++){
			for(int j=0;j<aa[i-1].size();j++) upd(1,0,aa[i-1][j]-1,0,n,1); 
			for(int j=0;j<aa[i].size();j++) upd(-1,aa[i][j],n,0,n,1);
			anss[i]=minn[1];
		}
		for(int i=1;i<=m;i++) ans+=anss[b[i]];
		cout<<ans<<endl;
	}
	return 0;
}