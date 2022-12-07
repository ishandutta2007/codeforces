#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
pair<long long,long long> a[200005];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].second,&a[i].first);
	sort(a+1,a+n+1);
	int l=1,r=n;
	long long ans=0;
	for (int i=1;i<=n;i++)
		ans+=a[i].second;
	long long buy=0;
	for (;;){
		for (;l<=r&&!a[l].second;++l);
		for (;l<=r&&!a[r].second;--r);
		if (l>r) break;
		if (buy>=a[l].first){
			buy+=a[l].second;
			a[l].second=0;
		}
		else{
			long long temp;
			temp=min(a[r].second,a[l].first-buy);
			buy+=temp; a[r].second-=temp; ans+=temp;
		}
	}
	cout<<ans<<endl;
}