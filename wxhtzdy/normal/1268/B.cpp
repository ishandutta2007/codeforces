#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300050;
int n,a[N];
ll cnt[2];
int main(){
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	for(int i=1;i<=n;i++){
		if(i%2==0){
			cnt[0]+=a[i]/2;
			cnt[1]+=(a[i]+1)/2;
		}else{
			cnt[0]+=(a[i]+1)/2;
			cnt[1]+=a[i]/2;
		}
	}
	printf("%lld",min(cnt[0],cnt[1]));
	return 0;
}