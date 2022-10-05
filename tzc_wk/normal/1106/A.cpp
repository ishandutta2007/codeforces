#include <bits/stdc++.h>
using namespace std;
int n;
char g[501][501];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>g[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<n-1;i++){
		for(int j=1;j<n-1;j++){
			if(g[i][j]=='X'&&g[i-1][j-1]=='X'&&g[i-1][j+1]=='X'&&g[i+1][j-1]=='X'&&g[i+1][j+1]=='X')
				ans++;
		}
	}
	cout<<ans<<endl;
}