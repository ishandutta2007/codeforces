#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int n,a[N],b[N],mn[N];
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		scanf("%i",&n);
		for(int i=1;i<=n;i++)scanf("%i",&a[i]);
		for(int i=1;i<=n;i++)scanf("%i",&b[i]);
		mn[1]=a[1];
		for(int i=2;i<=n;i++)mn[i]=min(mn[i-1],a[i]);
		int ans=2*n;
		for(int i=1;i<=n;i++){
			int bot=1,top=n,pos=1;
			while(bot<=top){
				int mid=bot+top>>1;
				if(mn[mid]<b[i])pos=mid,top=mid-1;
				else bot=mid+1;
			}
			ans=min(ans,i+pos-2);
		}
		printf("%i\n",ans);
	}
	return 0;
}