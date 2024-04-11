#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
int n;
char s[maxn],t[maxn];
int c1,c2,c3,c4;
ll ans;
// 0 1 : 1
// 1 0 : 1
// 0 0 : 0
// 1 1 : 1
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%d %s %s",&n,s+1,t+1);
	for (int i=1;i<=n;i++) {
		if (s[i]=='0'&&t[i]=='1') c1++;
		else if (s[i]=='1'&&t[i]=='0') c2++;
		else if (s[i]=='0'&&t[i]=='0') c3++;
		else c4++;
	}
	ans=(ll)c1*c2+(ll)c2*c3+(ll)c3*c4;
	printf("%I64d\n",ans);
	return 0;
}