/// copied
#include<bits/stdc++.h>
using namespace std;
const int N=4e5+3,B=999,M=409; 
int a[N],b[N],bl[N],l[M],r[M],w[M];
int main(){
	int n,m,i,j,k,u,o,s=0;
	scanf("%d%d",&n,&m),a[1]=1;
	for(i=2;i<=n;++i)scanf("%d",a+i);
	for(i=n;i;--i)l[bl[i]=i/B]=i;
	for(i=1;i<=n;++i)if(r[bl[i]]=i,(b[i]=a[i])>=l[bl[i]])b[i]=b[b[i]];
	while(m--)if(scanf("%d%d%d",&i,&j,&k),i==1){
		for(scanf("%d",&u),i=min(k,r[bl[j]]);i>=j;--i)a[i]=max(a[i]-u,1);
		if(bl[j]!=bl[k])for(i=l[bl[k]];i<=k;++i)a[i]=max(a[i]-u,1);
		for(i=bl[j]+1;i<bl[k];++i)w[i]=min(w[i]+u,N);
		for(i=bl[j];i<=bl[k];++i)if(w[i]<B)for(o=l[i];o<=r[i];++o)if((b[o]=max(a[o]-w[i],1))>=l[i])b[o]=b[b[o]];
	}else{
		while(j!=k){
			if(j<k)swap(j,k);
			if(w[bl[j]]>=B||(bl[j]==bl[k]&&b[j]==b[k]))j=max(a[j]-w[bl[j]],1);else j=b[j];
		}
		printf("%d\n",s=j);
	}
	return 0;
}