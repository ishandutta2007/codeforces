#include<bits/stdc++.h>

using namespace std;

const int N=1005;
int n,a[N][8];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=5;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=5;i++)
		for (int j=i+1;j<=5;j++){
			int s1=0,s2=0,fl=0;
			for (int k=1;k<=n;k++){
				if (a[k][i]) ++s1;
				if (a[k][j]) ++s2;
				if (!a[k][i]&&!a[k][j]) fl=1;
			}
			if (!fl&&s1>=n/2&&s2>=n/2)
				return puts("YES"),void(0);
		}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}