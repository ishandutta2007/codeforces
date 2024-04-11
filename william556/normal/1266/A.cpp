#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
char s[105];
void solve(){
	scanf("%s",s);
	int n=strlen(s);
	int sum=0,cnt=0,flag=0;
	for(int i=0;i<n;i++){
		sum+=s[i]-'0';
		if(s[i]=='0')flag=1;
		if((s[i]-'0')%2==0)cnt++;		
	}
	if(sum==0||(flag&&cnt>=2&&sum%3==0))puts("red");
	else puts("cyan");
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}