#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1050],f[1050],p[1050];

#define M 1000000007

int su(int a,int b){
	a+=b;return (a>=M)?a-M:a;
}

int main(){
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++){
		f[i]=2;
		f[i]=su(f[i],p[i-1]);
		f[i]=su(f[i],M-p[a[i]-1]);
		p[i]=su(p[i-1],f[i]);
	}
	cout<<p[n];
}