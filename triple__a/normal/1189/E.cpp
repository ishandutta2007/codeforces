#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const int maxn=300007;

ll n,p,k;
ll a[maxn],ans[maxn];
bool fg[maxn];

ll mult(ll a,ll b){
	return (a*b)%p;
}

int main(){
	memset(fg,0,sizeof(fg));
	scanf("%lld%lld%lld",&n,&p,&k);
	for (int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int i=1;
	while(i<=n){
		int u=a[i],j=i;
		while (j<n&&a[j]==a[j+1]){
			j++;
		}
		if (mult(mult(4*a[j],a[j]),a[j])!=k){
			for (int k=i;k<j;++k){
				fg[k]=1;
			}
		}
		i=j+1;
	}
	int j=0;
	for (int i=1;i<=n;++i){
		if (!fg[i]){
			ans[++j]=((mult(mult(a[i],a[i]),mult(a[i],a[i]))-mult(k,a[i]))%p+p)%p;
		}
	}
	ll ret=0;
	sort(ans+1,ans+1+j);
	i=1;
	while (i<=j){
		int u=ans[i],k=i;
		while(k<j&&ans[k]==ans[k+1]){
			k++;
		}
		ret+=(k-i+1)*(k-i)/2;
		k++;
		i=k;
	}
	printf("%lld\n",ret);
	return 0;
}