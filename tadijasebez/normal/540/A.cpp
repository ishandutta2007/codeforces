//	:(	:(	:(
#include <bits/stdc++.h>
using namespace std;
//	:(	:(	:(
const int N=1050;
char s[N],t[N];
int main(){
//	:(	:(	:(

	int n;scanf("%i",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	int ans=0;
	for(int i=1;i<=n;i++)ans+=min(abs(s[i]-t[i]),10-abs(s[i]-t[i]));
	printf("%i\n",ans);
	return 0;
}
//	:(	:(	:(