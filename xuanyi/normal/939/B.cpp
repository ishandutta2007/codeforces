#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXK=100005;
ll n,k,min_x,id,a[MAXK];
int main(){
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=k;i++) scanf("%lld",&a[i]);
	min_x=n%a[1],id=1;
	for (int i=2;i<=k;i++){
		if (n%a[i]<min_x) min_x=n%a[i],id=i;
	}
	printf("%lld %lld\n",id,n/a[id]);
	return 0;
}