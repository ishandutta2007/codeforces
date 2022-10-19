using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 200001
#define ll long long
#define int ll
int n,k,p;
int a[N];
int b[N],ans;
int l,r;
bool pd(int x) {
	int kk=1;
	for(int i=1;i<=n;i++) {
		while(abs(a[i]-b[kk])+abs(b[kk]-p)>x&&kk<=k) {
			kk++;
		}
		if(kk>k) return 0;
		kk++;
	}
	return 1;
}
main() {
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=k;i++) cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+k+1);
	l=0;r=1e10;
	while(l<=r) {
		int mid=(l+r)>>1;
//		cout<<mid<<endl;
		if(pd(mid)) {
			ans=mid;r=mid-1;
		}
		else
		l=mid+1;
	}
	cout<<ans<<endl;
}