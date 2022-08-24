#include <bits/stdc++.h>
using namespace std;
long long K,d,t;
int main(){
	scanf("%I64d%I64d%I64d",&K,&d,&t);
	d=((K-1)/d+1)*d;
	t=t*2;
	long long now=K*2+d-K;
	long long k1=t/now,rem=t%now;
	long long ans=d*k1,ans2=0;
	//cout<<rem<<" "<<k1<<endl;
	if (rem<=K*2) ans+=rem/2,ans2=rem%2;
	else ans+=K+rem-K*2;
	printf("%I64d",ans);
	if (ans2) cout<<".5"<<endl; else cout<<endl;
	return 0;
}