#include<bits/stdc++.h>

using namespace std;

int a[1000], f[1000][5];

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	f[0][0] = f[0][1] = f[0][2] = 0;
	for(int i = 1; i <= n; i++){
	//	f[i][0] = f[i][1] = f[i][2] = 0;
		if (a[i] & 1){
			f[i][0] = max(f[i-1][2], f[i-1][1]) + 1;
		}
		else
			f[i][0] = 0;
		if (a[i] & 2){
			f[i][1] = max(f[i-1][2], f[i-1][0]) + 1;
		}
		else
			f[i][1] = 0;
		f[i][2] = max(f[i - 1][0], max(f[i - 1][1], f[i - 1][2]));
	//	cout<<i<<' '<<f[i][0]<<' '<<f[i][1]<<' '<<f[i][2]<<endl;
	}
	int ans = max(f[n][0], max(f[n][1], f[n][2]));
	printf("%d\n", n - ans);
	return 0;
}