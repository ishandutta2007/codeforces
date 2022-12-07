#include<bits/stdc++.h>

using namespace std;

const int N=200005;

int n;
long long k;
int a[N];
void solve(){
	scanf("%d%lld",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),k-=a[i];
	if (k>=0) return puts("0"),void(0);
	sort(a+1,a+n+1);
	long long re=1ll<<60;
	for (int i=1;i<=n;i++){
		k+=(i==1?a[1]:a[n-i+2]);
		long long v=(k>=0?k/i:(-k+i-1)/i*(-1));
		re=min(re,i-1+max(0ll,a[1]-v));
	}
	cout<<re<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}