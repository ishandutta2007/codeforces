//	:(	:(	:(
#include <bits/stdc++.h>
using namespace std;
//	:(	:(	:(
const int N=100050;
char s[N];
int main(){
//	:(	:(	:(

	int a[5];for(int i=1;i<=4;i++)scanf("%i",&a[i]);
	scanf("%s",s+1);
	int n=strlen(s+1),ans=0;
	for(int i=1;i<=n;i++)ans+=a[s[i]-'0'];
	printf("%i\n",ans);
	return 0;
}
//	:(	:(	:(