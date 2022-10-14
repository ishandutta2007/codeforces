#include<bits/stdc++.h>
const int N=1e5+5;
int n,a[N],s[N],i,j,k;
inline int ask(int l,int r){
	return s[r]^s[l-1];
}
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i),s[i]=s[i-1]^a[i];
	for(i=2;i<n;++i){
		bool fl=0;
		for(j=1;j+i<=n;++j)for(k=j;k<j+i;++k)if(ask(j,k)>ask(k+1,j+i))fl=1;
		if(fl){
			printf("%d\n",i-1);
			return 0;
		}
	}
	puts("-1");
}