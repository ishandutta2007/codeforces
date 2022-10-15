#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=200007;
int n,k,a[maxn];

bool ck(int t){
	ll sum=0; 
	for (int i=n/2+1;i<=n;++i){
		sum+=max(0,t-a[i]);
	}
	if (sum>k) return 0;
	return 1;
}

int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	long long l=1,r=2e9,md=(l+r)>>1;
	while(l<r){
//		cout<<l<<" "<<r<<endl;
		md=(l+r)>>1;
		if (ck(md+1)){
			l=md+1;
		}
		else{
			r=md;
		}
	}
	cout<<l<<endl;
	return 0;
}