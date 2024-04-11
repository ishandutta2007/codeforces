#include <bits/stdc++.h>
using namespace std;
int main(){
	/*freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);*/
	int n;
	scanf("%i",&n);
	char s[n];
	scanf("%s",&s);
	int ans=0;
	for(int i=1;i<n-1;i++){
		if(s[i-1]==s[i+1]){
			if(s[i-1]=='R'&&s[i]=='R'){
				s[i]='B';
				ans++;
			}
			if(s[i-1]=='B'&&s[i]=='B'){
				s[i]='R';
				ans++;
			}
			if(s[i-1]=='G'&&s[i]=='G'){
				s[i]='B';
				ans++;
			}
		}
	}
	for(int i=1;i<n;i++){
		if(s[i]==s[i-1]){
			if(s[i-1]=='R'){
				if(i==n-1||s[i+1]=='B')s[i]='G',ans++;
				else s[i]='B',ans++;
			}
			if(s[i-1]=='B'){
				if(i==n-1||s[i+1]=='R')s[i]='G',ans++;
				else s[i]='R',ans++;
			}
			if(s[i-1]=='G'){
				if(i==n-1||s[i+1]=='B')s[i]='R',ans++;
				else s[i]='B',ans++;
			}
		}
	}
	printf("%i\n%s",ans,s);
	return 0;
}