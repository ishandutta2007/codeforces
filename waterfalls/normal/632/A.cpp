#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,p;
char buff[13];
bool go[43];

int main() {
	scanf("%d%d",&n,&p);
	ll cur = 0;
	ll other = 0;
	for (int i=0;i<n;i++) {
		scanf(" %s",&buff);
		if (buff[4]=='p') go[i] = 1;
	}
	for (int i=n-1;i>=0;i--) {
		cur*=2;
		if (go[i]) cur+=1, other+=1;;
	}
	printf("%lld\n",cur*p-other*p/2);

	return 0;
}