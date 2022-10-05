#include<bits/stdc++.h>
using namespace std;
const int B=200;
struct query{
	int l,r,i;
}q[40000];
bool cmp(query tt,query ty){
	if(tt.l/B!=ty.l/B) return tt.l<ty.l;
	if((tt.l/B)&1) return tt.r<ty.r;
	return tt.r>ty.r;
}
int m;
int f[40000];
int a[40000];
int b[40000];
int tot=0;
int c[40000];
int cnt[40000]={};
int o1[160000]={};
int o0[160000]={};
int num[160000]={};
int ans[40000];
void addo(int x,int l,int r,int p){
	num[p]++;
	if(l==r){
		o1[p]=c[x]%m;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) addo(x,l,mid,2*p);
	else addo(x,mid+1,r,2*p+1);
	if(num[2*p]==0) o0[p]=o0[2*p+1];
	else o0[p]=(o0[2*p]+1ll*o0[2*p+1]*f[num[2*p]-1]+1ll*o1[2*p+1]*f[num[2*p]])%m;
	o1[p]=(o1[2*p]+1ll*o0[2*p+1]*f[num[2*p]]+1ll*o1[2*p+1]*f[num[2*p]+1])%m;
}
void delo(int x,int l,int r,int p){
	num[p]--;
	if(l==r){
		o1[p]=0;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) delo(x,l,mid,2*p);
	else delo(x,mid+1,r,2*p+1);
	if(num[2*p]==0) o0[p]=o0[2*p+1];
	else o0[p]=(o0[2*p]+1ll*o0[2*p+1]*f[num[2*p]-1]+1ll*o1[2*p+1]*f[num[2*p]])%m;
	o1[p]=(o1[2*p]+1ll*o0[2*p+1]*f[num[2*p]]+1ll*o1[2*p+1]*f[num[2*p]+1])%m;
}
void add(int x){
	cnt[x]++;
	if(cnt[x]==1) addo(x,1,tot,1);
}
void del(int x){
	cnt[x]--;
	if(cnt[x]==0) delo(x,1,tot,1);
}
int main(){
	f[0]=0;
	f[1]=1;
	int n;
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++) f[i]=(f[i-1]+f[i-2])%m; 
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if((i==1)||((i>1)&&(b[i]>b[i-1]))) c[++tot]=b[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=tot;
		for(;l<r;){
			if(c[(l+r)/2]>=a[i]) r=(l+r)/2;
		    else l=(l+r)/2+1;
		}
		a[i]=l;
	}
	int qq;
	scanf("%d",&qq);
	for(int i=1;i<=qq;i++){
		q[i].i=i;
		scanf("%d%d",&q[i].l,&q[i].r);
	} 
	sort(q+1,q+qq+1,cmp);
	int l=1,r=0;
	for(int i=1;i<=qq;i++){
		if(l<q[i].l){
			for(;l<q[i].l;l++){
				if(l<=r) del(a[l]);
			}
		}
		else{
			for(;l>q[i].l;l--) add(a[l-1]);
		}
		if(r<q[i].r){
			for(;r<q[i].r;r++){
				if(l<=r+1) add(a[r+1]);
			}
		}
		else{
			for(;r>q[i].r;r--) del(a[r]);
		} 
		ans[q[i].i]=o1[1];
	}
	for(int i=1;i<=qq;i++) printf("%d\n",ans[i]);
	return 0;
}