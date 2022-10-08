#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N=1005;
int n,m,a[N][N],s1[N][N],s2[N][N],ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			s1[i][j]=s1[i][j-1]+a[i][j];
			s2[i][j]=s2[i-1][j]+a[i][j];
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(a[i][j]) continue;
			else {
				if (s1[i][j-1]) ans++;
				if (s1[i][m]-s1[i][j]) ans++;
				if (s2[i-1][j]) ans++;
				if (s2[n][j]-s2[i][j]) ans++;
			}
		}
	cout <<ans<<endl;
	return 0;
}