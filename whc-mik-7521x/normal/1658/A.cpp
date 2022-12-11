#include<bits/stdc++.h>
using namespace std;
int t,n;
char s[100000]; 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,s+1);
		int ans=0;
		for(int i=2;i<=n;i++){
            ans+=s[i]=='0'&&s[i-1]=='0'?2:s[i]=='0'&&s[i-2]=='0'?1:0;
        }
		printf("%d\n",ans);
	}
	return 0;
}