#include<bits/stdc++.h>
using namespace std;
int n;
long long res=0x3f3f3f3f3f3f3f3f;
int query(int x){
	printf("? %d\n",x),fflush(stdout);
	scanf("%d",&x);return x;
}
int main(){
	scanf("%d",&n);
	int l=1,r=5e6;
	while(l<r){
		int mid=(l+r)>>1;
		if(query(mid)==1)r=mid;else l=mid+1;
	}
	int sum=l+1;
	for(int i=1;i<=n;i++){
		int qwq=(sum-1)/i;
		if(qwq){
			int qaq=query(qwq);
			if(qwq&&qaq)res=min(res,1ll*qwq*qaq);
		}
	}
	printf("! %lld\n",res);
	return 0;
}