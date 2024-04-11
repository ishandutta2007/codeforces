#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
int n,k,a[N],ord[N];
bool rem[N];
int main(){
	int t;scanf("%i",&t);
	while(t--){
		scanf("%i%i",&n,&k);
		for(int i=1;i<=n;i++)scanf("%i",&a[i]),ord[i]=i,rem[i]=false;
		sort(ord+1,ord+1+n,[&](int i,int j){return -a[i]+n-i<-a[j]+n-j;});
		for(int i=1;i<=k;i++)rem[ord[i]]=true;
		ll ans=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(rem[i])cnt++;
			else ans+=a[i]+cnt;
		}
		printf("%lld\n",ans);
	}
	return 0;
}