#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,c[110500][205],f[100500][105],a[100500],l,r,w;

#define M 1000000007

int su(int a,int b){
	a+=b;return (a>=M)?a-M:a;
}

int main(){
	c[0][0]=1;
	for(i=1;i<=110005;i++){
		c[i][0]=1;
		for(j=1;j<=205;j++){
			c[i][j]=su(c[i-1][j-1],c[i-1][j]);
		}
	}
	cin.tie(0);
	cin>>n>>t;
	for(i=1;i<=n;i++){
		cin>>a[i];
		f[i][0]=su(a[i],M-a[i-1]);
	}
	while(t--){
		cin>>l>>r>>w;
		f[l][w]++;
		for(i=w;i>=0;i--){
			//printf("a%d %d\n",i,c[w-i+r-l][w-i]);
			f[r+1][i]=su(f[r+1][i],M-c[w-i+r-l][w-i]);
		}
	}
	for(i=100;i>=0;i--){
		for(j=1;j<=n;j++){
			f[j][i]=su(f[j][i],f[j][i+1]);
			f[j][i]=su(f[j][i],f[j-1][i]);
		}
	}
	for(i=1;i<=n;i++){
		cout<<f[i][0]%M<<' ';
	}
}