#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n;
char s[N];
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=n-1;i>=1;i--)
		if ((s[i]-'0')+(s[i+1]-'0')>=10){
			int v=(s[i]-'0')+(s[i+1]-'0');
			s[i]='1'; s[i+1]=v-10+'0';
			printf("%s\n",s+1);
			return;
		}
	s[2]=s[2]+s[1]-'0';
	printf("%s\n",s+2);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}