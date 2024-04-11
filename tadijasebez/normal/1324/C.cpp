#include <bits/stdc++.h>
using namespace std;
const int N=200050;
char s[N];
int main(){
	int n;
	scanf("%i",&n);
	while(n--){
		scanf("%s",s+1);
		int len=strlen(s+1);
		int las=0,ans=0;
		for(int i=1;i<=len;i++){
			if(s[i]=='R'){
				ans=max(ans,i-las);
				las=i;
			}
		}
		ans=max(ans,len+1-las);
		printf("%i\n",ans);
	}
	return 0;
}