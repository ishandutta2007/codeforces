#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=505;
int n,l,k;
int d[N],a[N];
int f[N][N];
int main(){
	n=in(),l=in(),k=in();
	for(int i=1;i<=n;i++)d[i]=in();
	for(int i=1;i<=n;i++)a[i]=in();
	d[n+1]=l;
	f[1][0]=0;
	for(int i=2;i<=n+1;i++){
		for(int j=0;j<=k;j++)f[i][j]=1e9;
		for(int j=1;j<i;j++){
			for(int o=max(0,i-j-1);o<=k;o++){
				f[i][o]=min(f[i][o],f[j][o-(i-j-1)]+(d[i]-d[j])*a[j]);
			}
		}
	}
	cout<<f[n+1][k];
	return 0;
}