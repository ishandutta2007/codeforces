#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,a[501][501],p=0,ans=0;
inline void init(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<k;j++)
			a[i][j]=(++p);
	for(int i=1;i<=n;i++)
		for(int j=k;j<=n;j++)
			a[i][j]=(++p);
	for(int i=1;i<=n;i++)
		ans+=a[i][k];
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
int main(){
	init();
	return 0;
}