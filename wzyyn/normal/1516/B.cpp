#include<bits/stdc++.h>
using namespace std;
int a[2005],n;

void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int s=0;
	for (int i=1;i<=n;i++)
		s^=a[i];
	if (s==0) puts("YES");
	else{
		int f1=0;
		int ss=0;
		for (int i=1;i<=n;i++){
			ss^=a[i];
			if (ss==s) f1=1;
			else if (f1&&!ss){
				puts("YES");
				return;
			}
		}
		puts("NO");
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while (t--) solve();
}