#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m;
bool a[100100],b[100100];
ll calc(){
	ll ret=0;
//	for(int i=1;i<=n;i++)printf("%d",a[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d",b[i]);puts("");
	for(int i=1,j=1,k=1;i<=n;i++){
		if(a[i]){
			while(!b[j])j++;
			ret+=abs(i-j);
//			printf("(%d,%d)\n",i,j);
			j++;
		}else{
			while(b[k])k++;
			ret+=abs(i-k);
//			printf("(%d,%d)\n",i,k);
			k++; 
		}
	}
	return ret>>1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),m=0;
		for(int i=1,x;i<=n;i++)scanf("%d",&x),a[i]=x&1,m+=a[i];
		if(abs(n-2*m)>1){puts("-1");continue;}
		if(n&1){
			if(2*m==n+1)for(int i=1;i<=n;i++)b[i]=i&1;
			else for(int i=1;i<=n;i++)b[i]=!(i&1);
			printf("%lld\n",calc());
		}else{
			ll res=0x3f3f3f3f3f3f3f3f;
			for(int i=1;i<=n;i++)b[i]=i&1;
			res=min(res,calc());
			for(int i=1;i<=n;i++)b[i]=!(i&1);
			res=min(res,calc());
			printf("%lld\n",res);
		}
	}
	return 0;
}