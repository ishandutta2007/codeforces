#include<bits/stdc++.h>
using namespace std;
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		char s[110];
		scanf("%d%s",&n,s+1);
		int cnt=0;
		for(int i=1;i<n;i++){
			if((s[i]=='0')&&(s[i+1]=='0')) cnt++;
		}
		int cnt2=0;
		for(int i=1;i<n-1;i++) if((s[i]=='0')&&(s[i+1]=='1')&&(s[i+2]=='0')) cnt2++;
		printf("%d\n",2*cnt+cnt2);
	}
	return 0;
}