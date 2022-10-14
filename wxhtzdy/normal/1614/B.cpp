#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int a[N],id[N],ans[N];
int main(){
	int tt;
	scanf("%i",&tt);
	while(tt--){
		int n;
		scanf("%i",&n);
		for(int i=0;i<n;i++)scanf("%i",&a[i]),id[i]=i;
		sort(id,id+n,[&](int i,int j){return a[i]>a[j];});
		int l=n/2-1,r=n/2+1;
		ans[0]=n/2;
		for(int i=0;i<n;i++){
			if(i&1)ans[id[i]+1]=l,l--;
			else ans[id[i]+1]=r,r++;
		}
		long long s=0;
		for(int i=1;i<=n;i++){
			s+=a[i-1]*1LL*abs(ans[i]-ans[0]);
		}
		printf("%lld\n",s*2);
		for(int i=0;i<n+1;i++)printf("%i ",ans[i]);
		printf("\n");
	}
	return 0;
}