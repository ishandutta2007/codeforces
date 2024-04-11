#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
ll a[100005];

ll f(int x){
	ll k=n/x,y=(k-1)*k/2;
	return x*y+k;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i*i<=n;++i) if (n%i==0) a[++*a]=f(i),a[++*a]=f(n/i);
	sort(a+1,a+1+*a);
	n=unique(a+1,a+1+*a)-a-1;
	for (int i=1;i<=n;++i) printf("%I64d ",a[i]);
	return 0;
}