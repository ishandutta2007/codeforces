#include<bits/stdc++.h>
using namespace std;
int n;
int a[1100][1100];
int main(){
	int T;
	scanf("%d",&T);
	for(int pp=0;pp<T;pp++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) scanf("%d",&a[i][j]); 
		}
		int ans=0;
			for(int i=3;i<=n;i+=4){
				for(int j=1;j<=i;j+=2) ans^=a[j][i-j+1];
			}
			for(int i=1;i<=n;i+=4){
				for(int j=1;j<=i;j+=2) ans^=a[n-j+1][n-(i-j+1)+1];
			}
			
			for(int i=3;i<=n;i+=4){
				for(int j=1;j<=i;j+=2) ans^=a[n+1-j][i-j+1];
			}
			for(int i=1;i<=n;i+=4){
				for(int j=1;j<=i;j+=2) ans^=a[j][n-(i-j+1)+1];
			}
		printf("%d\n",ans);
	}
	return 0;
}