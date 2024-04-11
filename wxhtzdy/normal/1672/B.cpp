#include <bits/stdc++.h>
using namespace std;

const int N=200050;
int n;
char s[N];
bool solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	if(s[n]=='A')return false;
	int bal=0;
	for(int i=1;i<=n;i++){
		bal+=(s[i]=='A'?1:-1);
		if(bal<0)return false;
	}
	return true;
}

int main(){
	int t;scanf("%i",&t);
	while(t--)puts(solve()?"YES":"NO");
	return 0;
}