#include <bits/stdc++.h>
using namespace std;

char str[1000100];
int n;

int main() {
	scanf("%d%s",&n,str);

	int pre=0, cur=0, ans=0;
	for(int i=0;i<n;i++) {
		cur = pre + (str[i] == '(' ? 1 : -1);
		if(pre < 0 || cur < 0) ans++;
		pre = cur;
	}
	if(cur != 0) puts("-1");
	else printf("%d\n",ans);

	return 0;
}