#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[210000];
int b[210000];
int mex;
int num[210000];
int f[210000]={};
int main(){
	int T;
	scanf("%d",&T);
	for(int pp=0;pp<T;pp++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=0;i<=n+1;i++) num[i]=0;
		m=0;
		for(int i=1;i<=n;i++) num[a[i]]++;
		for(int i=0;;i++){
			if(num[i]==0){
				mex=i;
				break;
			}
		}
		int j=0;
		for(;;){
			int mexx=mex,s=0,i=j+1;
			for(;;i++){
				if((a[i]<mex)&&(f[a[i]]==0)) s++;
				num[a[i]]--;
				if(num[a[i]]==0) mexx=min(mexx,a[i]);
				f[a[i]]++;
				if(s==mex) break;
			}
			for(int u=j+1;u<=i;u++) f[a[u]]--;
			m++;
			b[m]=mex;
			mex=mexx;
			j=i;
			if(j==n) break;
		}
		printf("%d\n",m);
		for(int i=1;i<=m;i++) printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}