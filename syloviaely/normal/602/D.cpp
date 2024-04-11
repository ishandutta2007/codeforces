#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int w[110000],a[110000],n,x[110000],f[110000],size[110000];
int compare(int k1,int k2){
	return w[k1]<w[k2];
}
int findfather(int k1){
	if (f[k1]==k1) return k1; f[k1]=findfather(f[k1]); return f[k1];
}
int main(){
	int q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++) w[i]=abs(x[i]-x[i-1]),a[i]=i;
	sort(a+1,a+n+1,compare);
	for (;q;q--){
		int l,r; scanf("%d%d",&l,&r);
		for (int i=1;i<=n;i++) f[i]=i,size[i]=1;
		long long ans=0;
		for (int now=1;now<=n;now++)
			if (a[now]>l&&a[now]<=r){
				int k1=findfather(a[now]-1),k2=findfather(a[now]);
		//		cout<<"fa "<<a[now]<<" "<<w[a[now]]<<" "<<size[k1]<<" "<<size[k2]<<endl;
				ans=(ans+1ll*size[k1]*size[k2]*w[a[now]]);
				if (size[k1]>size[k2]) swap(k1,k2);
				f[k1]=k2; size[k2]+=size[k1];
			}
		printf("%I64d\n",ans);
	}
	return 0;
}