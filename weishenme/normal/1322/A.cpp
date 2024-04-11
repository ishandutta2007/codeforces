#include<bits/stdc++.h>
using namespace std;
int n,ans;
char s[1000005];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int l=0;
	for (int i=1;i<=n;i++)l+=s[i]=='('?1:-1;
	if (l!=0){
		puts("-1");
		return 0;
	}
	for (int i=1,j=1;i<=n;i=j){
		int v=0;
		while (j<=n&&v>=0){
			v+=s[j]=='('?1:-1;
			j++;
			if (v==0)break;
		}
		if (v==0)continue;
		if (j>n)break;
		while (v<0)v+=s[j]=='('?1:-1,j++;
		ans+=j-i;
	}
	printf("%d\n",ans);
}