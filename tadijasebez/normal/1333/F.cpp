#include <bits/stdc++.h>
using namespace std;
const int N=10000050;
bool out[N];
int ans[N];
int main(){
	int n;
	scanf("%i",&n);
	int cnt=n;
	for(int i=1;i<=n;i++)ans[i]=n;
	for(int i=n;i>=1;i--){
		for(int j=i*2;j<=n;j+=i){
			if(!out[j])cnt--;
			out[j]=1;
		}
		ans[cnt]=min(ans[cnt],i-1);
	}
	for(int i=n-1;i>=2;i--)ans[i]=min(ans[i],ans[i+1]);
	for(int i=2;i<=n;i++)printf("%i ",ans[i]);
	return 0;
}