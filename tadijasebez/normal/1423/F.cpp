#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	ll c=0;int s=0;
	while(k--){
		int a,b;
		scanf("%i %i",&a,&b);
		c+=b;
		s+=(ll)(a-1)*b%n;
		if(s>=n)s-=n;
	}
	int o=((ll)n*(n-1)/2)%n;
	if(c<n||o==s)printf("1\n");
	else printf("-1\n");
	return 0;
}