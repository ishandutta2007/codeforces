#include<bits/stdc++.h>
using namespace std;
int a[110000]; 
int s[410000][40];
void build(int l,int r,int p){
	if(l==r){
		s[p][0]=a[l];
		for(int i=1;i<=35;i++)s[p][i]=(1<<30)-1;
		return;
	}
	build(l,(l+r)/2,2*p);
	build((l+r)/2+1,r,2*p+1);
	int u[80];
	for(int i=0;i<=35;i++)u[i]=s[2*p][i];
	for(int i=0;i<=35;i++)u[i+36]=s[2*p+1][i];
	sort(u,u+72);
	for(int i=0;i<=35;i++)s[p][i]=u[i];
}
int o[40];
void query(int x,int y,int l,int r,int p){
	if(x<=l&&y>=r){
		int u[80];
		for(int i=0;i<=35;i++)u[i]=o[i];
		for(int i=0;i<=35;i++)u[i+36]=s[p][i];
		sort(u,u+72);
		for(int i=0;i<=35;i++)o[i]=u[i];
		return;
	}
	int md=(l+r)/2;
	if(x<=md)query(x,y,l,md,2*p);
	if(y>=md+1)query(x,y,md+1,r,2*p+1);
}
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		build(1,n,1);
		int q;
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			for(int i=0;i<=35;i++)o[i]=(1<<30)-1;
			query(l,r,1,n,1);
			int ans=(1<<30)-1;
			for(int i=0;i<35;i++){
				for(int j=i+1;j<=35;j++)ans=min(ans,o[i]|o[j]);
			}
			printf("%d\n",ans);
		}
	}
	return 0; 
}