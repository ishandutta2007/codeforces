#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int pos[MN], n, i, ans=1<<30;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&pos[i]);
	sort(pos+1, pos+n+1);
	pos[0] = 1; pos[n+1] = 1e6;
	for(i=0;i<=n;i++)
		ans=min(ans,max(pos[i]-1,(int)1e6-pos[i+1]));
	printf("%d\n",ans);
	return 0;
}