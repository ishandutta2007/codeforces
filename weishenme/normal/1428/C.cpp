#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int T;
char s[N];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%s",s+1);
		int n=strlen(s+1),l=0,ans=0;
		for (int i=n;i;i--)
			if (s[i]=='A'){
				if (l)l--;
				else ans++;
			}
			else l++;
		ans+=l%2;
		printf("%d\n",ans);
	}
}