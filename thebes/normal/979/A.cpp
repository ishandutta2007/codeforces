#include <bits/stdc++.h>
using namespace std;

long long wtf, cnt;
int main(){
	scanf("%lld",&wtf); wtf++;
	if(wtf%2==0) printf("%lld\n",wtf/2);
	else if(wtf!=1) printf("%lld\n",wtf);
	else printf("0\n");
	return 0;
}