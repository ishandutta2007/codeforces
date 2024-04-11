#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long LL;

LL n,k,A,B;
LL ans=0;

int main(){
	cin>>n>>k>>A>>B;
	while(n>1){
		ans+=(n%k)*A;
		n-=n%k;
		if ((n-n/k)*A<=B) break;
		ans+=B;
		n/=k;
	}
	ans+=(n-1)*A;
	cout<<ans<<endl;
	return 0;
}