#include <bits/stdc++.h>
using namespace std;
const int N=105;
char s[N];
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		int n;
		scanf("%i %s",&n,s);
		int ans=0;
		for(int i=0;i<n;i++){
			if(s[i]!='0'){
				ans+=s[i]-'0';
				ans+=(i!=(n-1)?1:0);
			}
		}
		printf("%i\n",ans);
	}
	return 0;
}