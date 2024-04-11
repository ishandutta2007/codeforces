#include<bits/stdc++.h>

using namespace std;

const int N=105;
char s[N];
void solve(){
	scanf("%s",s+1);
	int l=strlen(s+1);
	s[l]=s[1];
	printf("%s\n",s+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}