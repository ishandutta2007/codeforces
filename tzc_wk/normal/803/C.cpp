#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,d,sum;
signed main(){
	cin>>n>>k;
	if(k>200000)	return puts("-1"),0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0&&i>=k*(k+1)/2){
			d=n/i;
			break;
		}
		if(n%i==0&&n/i>=k*(k+1)/2)	d=max(d,i);
	}
	if(d==0)		return puts("-1"),0;
	for(int i=1;i<k;i++){
		cout<<d*i<<" ";
		sum+=i;
	}
	cout<<n-sum*d<<endl;
	return 0;
}