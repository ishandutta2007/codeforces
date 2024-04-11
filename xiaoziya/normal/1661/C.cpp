#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,mx;
int a[maxn],b[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),mx=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),mx=max(mx,a[i]);
		long long L=-1,R=1e18;
		while(L+1<R){
			long long mid=(L+R)>>1,one=(mid+1)/2,two=mid-one;
			int FLG=0;
			for(int t=mx;t<=mx+1;t++){
				long long f=one,g=two;
				int flg=0;
				for(int i=1;i<=n;i++){
					if((t-a[i])&1)
						f--;
					long long c=min(g,0ll+(t-a[i])/2);
					g-=c,f-=((t-a[i])/2-c)*2;
					if(f<0){
						flg=1;
						break;
					}
				}
				if(flg==0){
					FLG=1;
					break;
				}
			}
			if(FLG)
				R=mid;
			else L=mid;
		}
		printf("%lld\n",R);
	}
	return 0;
}