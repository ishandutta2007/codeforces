#include<bits/stdc++.h>

using namespace std;

const int N=1005;
int n;
int a[N][N];
int tag[N][N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			tag[i][j]=0;
		}
	int ans=0;
	for (int i=2;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (!tag[i-1][j]){
				ans^=a[i][j];
				tag[i-1][j]^=1;
				tag[i+1][j]^=1;
				tag[i][j-1]^=1;
				tag[i][j+1]^=1;
			}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}