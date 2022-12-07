#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,Q;
long long a[N];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	long long S=0;
	for (int i=1;i<=n;i++)
		S+=a[i];
	scanf("%d",&Q);
	while (Q--){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		int p=lower_bound(a+1,a+n+1,x)-a;
		long long re=1ll<<60;
		if (p!=n+1) re=min(re,max(0ll,y-(S-a[p])));
		if (p!=1) re=min(re,x-a[p-1]+max(0ll,y-(S-a[p-1])));
		printf("%lld\n",re);
	}
}