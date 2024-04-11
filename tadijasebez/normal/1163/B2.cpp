#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int a[N],cnt[N],duo[N],mx,mn=1;
int main(){
	int n,ans=1;
	scanf("%i",&n);
	for(int i=1;i<=n;i++){
		scanf("%i",&a[i]);
		duo[cnt[a[i]]]--;
		cnt[a[i]]++;
		duo[cnt[a[i]]]++;
		mx=max(mx,cnt[a[i]]);
		mn=min(mn,cnt[a[i]]);
		while(duo[mn]==0)mn++;
		if(mx==mn+1 && duo[mx]==1)ans=i;
		if(duo[mx]==-duo[0]-1 && duo[1]==1)ans=i;
		if(mn==mx && mx==1)ans=i;
		if(mn==mx && duo[mx]==1)ans=i;
	}
	printf("%i\n",ans);
	return 0;
}