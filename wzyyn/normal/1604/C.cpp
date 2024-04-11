#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	bool flag=1;
	for (int i=1;i<=n&&i<=25;i++){
		bool ok=0;
		for (int j=2;j<=i+1&&j<=25;j++)
			if (a[i]%j) ok=1;
		if (!ok) flag=0;
	}
	puts(flag?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}