#include <bits/stdc++.h>
using namespace std;

int a, b, c, ans=1<<30;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	ans=min(ans,2*(a+b+c)-2*max(a,max(b,c)));
	ans=min(ans,a+b+c);
	printf("%d\n",ans);
	return 0;
}