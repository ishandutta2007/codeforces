#include <bits/stdc++.h>
using namespace std;

char a[200013], b[200013];

int main() {
	scanf("%s %s",&a,&b);
	int num = strlen(b)-strlen(a)+1;
	int cur = 0;
	for (int i=0;i<num;i++) cur+=(b[i]=='1');
	long long ans = 0;
	for (int i=0;a[i]!='\0';i++) {
		ans+=abs(num*(a[i]=='1')-cur);
		cur-=(b[i]=='1');
		cur+=(b[i+num]=='1');
	}
	printf("%lld\n",ans);

	return 0;
}