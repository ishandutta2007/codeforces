#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int a[N],n;
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if (n%2==0)
		puts("YES");
	else{
		int flag=0;
		for (int i=1;i<n;i++)
			if (a[i]>=a[i+1])
				flag=1;
		puts(flag?"YES":"NO");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}