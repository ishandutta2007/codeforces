#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int t;
	scanf("%i",&t);
	while(t--){
		int a,b;
		scanf("%i %i",&a,&b);
		int diff=abs(a-b);
		int d[5]={0,1,1,2,2};
		int ans=diff/5+d[diff%5];
		printf("%i\n",ans);
	}
	return 0;
}