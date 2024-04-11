#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[110000],f[110000],n,m,q,A[110000],wl[110000],wr[110000],root[110000],len;
const int mo=1e9+7;
struct tree{
	int w[3][3];
	int l,r;
}t[4000000];
void add(int k1,int k2){
	for (;k1<=m;k1+=k1&(-k1)) A[k1]+=k2;
}
int find(int k1){
	int ans=0; for (;k1;k1-=k1&(-k1)) ans+=A[k1]; return ans;
}
void change(int k1){
	int l=t[k1].l,r=t[k1].r;
	for (int i=0;i<3;i++)
		for (int j=i;j<3;j++){
			t[k1].w[i][j]=(t[l].w[i][j]+t[r].w[i][j])%mo;
			for (int k=i;k<j;k++)
				t[k1].w[i][j]=(t[k1].w[i][j]+1ll*t[l].w[i][k]*t[r].w[k+1][j])%mo;
		}
}
void insert(int k1,int k2,int k3,int k4){
	if (k2==k3){
		t[k1].w[0][0]=wl[k4];
		t[k1].w[1][1]=1;
		t[k1].w[2][2]=wr[k4];
		return;
	}
	int mid=k2+k3>>1;
	if (mid>=k4){
		if (t[k1].l==0) t[k1].l=++len; insert(t[k1].l,k2,mid,k4);
	} else {
		if (t[k1].r==0) t[k1].r=++len; insert(t[k1].r,mid+1,k3,k4);
	}
	change(k1);
}
void del(int k1,int k2,int k3,int k4){
	if (k2==k3){
		t[k1].w[0][0]=0;
		t[k1].w[1][1]=0;
		t[k1].w[2][2]=0;
		return;
	}
	int mid=k2+k3>>1;
	if (mid>=k4){
		if (t[k1].l==0) t[k1].l=++len; del(t[k1].l,k2,mid,k4);
	} else {
		if (t[k1].r==0) t[k1].r=++len; del(t[k1].r,mid+1,k3,k4);
	}
	change(k1);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),f[i]=a[i];
	sort(f+1,f+n+1); m=unique(f+1,f+n+1)-f-1;
	for (int i=1;i<=n;i++) a[i]=lower_bound(f+1,f+m+1,a[i])-f;
	for (int i=1;i<=n;i++){
		wl[i]=find(a[i]); add(a[i],1);
	}
	memset(A,0x00,sizeof A);
	for (int i=n;i;i--){
		wr[i]=find(a[i]); add(a[i],1);
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		if (root[a[i]]==0) root[a[i]]=++len;
		insert(root[a[i]],1,n,i);
	}
	for (int i=1;i<=m;i++) ans=(ans+t[root[i]].w[0][2])%mo;
	scanf("%d",&q);
	for (;q;q--){
		int k1,k2; scanf("%d%d",&k1,&k2);
		ans=(ans-t[root[a[k2]]].w[0][2]+mo)%mo;
		if (k1==2) insert(root[a[k2]],1,n,k2); else del(root[a[k2]],1,n,k2);
		ans=(ans+t[root[a[k2]]].w[0][2])%mo;
		printf("%d\n",ans);
	}
	return 0;
}