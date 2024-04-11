#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	if (b==1) puts("Yes");
	else if (a==1) puts(n%b==1?"Yes":"No");
	else{
		int v=1;
		for (;;){
			if ((n-v)%b==0)
				return puts("Yes"),void(0);
			if (1ll*v*a>n) break;
			v*=a;
		}
		puts("No");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}