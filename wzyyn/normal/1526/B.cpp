#include<bits/stdc++.h>
using namespace std;

void solve(){
	int x;
	scanf("%d",&x);
	if (x>=2*11*111)
		puts("YES");
	else{
		bool flag=0;
		for (int i=0;i<=22;i++)
			if (x>=i*111&&(x-i*111)%11==0)
				flag=1;
		puts(flag?"YES":"NO");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}