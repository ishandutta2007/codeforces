#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
ll n,l,r;
ll x[10],d[200005][10];

int main(){
	n=readint(); l=readint(); r=readint();
	x[0]=r/3-(l-1)/3,x[1]=(r-1)/3+1-(l+1)/3,x[2]=(r+1)/3-l/3;
	d[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				d[i][j]=(d[i][j]+d[i-1][k]*x[(k-j+3)%3]%cys)%cys;
			}
		}
	}
	cout<<d[n][0]<<endl;
	return 0;
}