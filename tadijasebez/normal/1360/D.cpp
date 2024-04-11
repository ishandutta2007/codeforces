#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;scanf("%i",&t);
	while(t--){
		int n,k;scanf("%i %i",&n,&k);
		int ans=n;
		auto Try=[&](int x){
			if(n/x<=k)ans=min(ans,x);
		};
		for(int i=1;i*i<=n;i++){
			if(n%i==0){
				Try(i);
				Try(n/i);
			}
		}
		printf("%i\n",ans);
	}
	return 0;
}