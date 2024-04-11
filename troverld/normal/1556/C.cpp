#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[1010];
ll res;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i+=2){
		ll mnx=1,dtx=0;
		for(int j=i+1;j<=n;j++){
			if(!(j&1)){
				res+=max(0ll,min(a[i]-mnx+1,a[j]-mnx-dtx+1));
				dtx-=a[j];
				mnx=max(mnx,-dtx);
			}else dtx+=a[j];
		}
	}
	printf("%lld\n",res);
	return 0;
}