using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define N 1000001
long long x,y,p,q;
int t;
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%lld%lld%lld%lld",&x,&y,&p,&q);
		if(p==q&&x!=y||x&&!p) {
			puts("-1");continue;
		}
		if(q>=y&&p>=x&&q-y>=p-x) {
			long long ans=q-y;
			cout<<ans<<endl;continue;
		}
		long long ans;
		long long l=1,r=1e9;
		while(l<=r) {
			long long mid=(l+r)>>1;
			if(mid*p>=x&&mid*q>=y&&(mid*p-x<=mid*q-y)) {
				ans=mid;r=mid-1;
			}
			else l=mid+1;
		}
		p*=ans;q*=ans;
		cout<<q-y<<endl;
	}
}