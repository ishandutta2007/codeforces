#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n;
	scanf("%i",&n);
	vector<int> a(n),b(n),c(n);
	for(int &i:a)scanf("%i",&i);
	ll ans=0;
	for(int i=0;i<n;i++){
		int mn=a[i];
		ll now=a[i];
		b[i]=a[i];
		for(int j=i-1;j>=0;j--)mn=min(mn,a[j]),now+=mn,b[j]=mn;
		mn=a[i];
		for(int j=i+1;j<n;j++)mn=min(mn,a[j]),now+=mn,b[j]=mn;
		if(ans<now)ans=now,c=b;
	}
	for(int i:c)printf("%i ",i);
	return 0;
}