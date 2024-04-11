#include<bits/stdc++.h>

int n,m;

int f[1<<19],mn[1<<19],mx[1<<19];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<(1<<m);i++)
		f[i]=mn[i]=1<<20,mx[i]=-1<<20;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		mn[x]=mx[x]=0;
	}
	for(int k=1;k<(1<<m);k<<=1)
		for(int i=0;i<(1<<m);i+=k<<1)
			for(int j=0;j<k;j++){
				int tmp=std::min(f[i+j],f[i+j+k]);
				int l0=mn[i+j],r0=mx[i+j],l1=mn[i+j+k],r1=mx[i+j+k];
				f[i+j]=std::min(tmp,l1+k-r0);
				f[i+j+k]=std::min(tmp,l0+k-r1);
				mn[i+j]=std::min(l0,l1+k);
				mn[i+j+k]=std::min(l1,l0+k);
				mx[i+j]=std::max(r0,r1+k);
				mx[i+j+k]=std::max(r1,r0+k);
			}
	for(int i=0;i<(1<<m);i++)
		printf("%d ",f[i]);
	puts("");
}