#include<bits/stdc++.h>
using namespace std;
long long query(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	long long x;
	scanf("%lld",&x);
	return x;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		long long x=query(1,n);
		long long l=1,r=n,mid,ans=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(query(mid,n)==x){
				l=mid+1;
				ans=mid;
			}
			else r=mid-1;
		}
		long long len=query(ans+1,n);
		len=x-len;
		long long now=query(ans+len+1,n)-query(ans+len+2,n);
		printf("! %lld %lld %lld\n",ans,ans+len+1,ans+len+now+1);
		fflush(stdout);
	}
	return 0;
}