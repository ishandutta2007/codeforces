#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int maxn = 1000000;

int g[maxn+7],s[17][maxn+7];

int fac(int n){
	int ans=1;
	while(n){
		int md=n%10;
		if (md){
			ans*=md;
		}
		n/=10;
	}
	return ans;
}

int main(){
	for (int i=1;i<=9;++i){
		g[i]=i;
	}
	for (int i=10;i<=maxn;++i){
		g[i]=g[fac(i)];
	}
	for (int i=1;i<=9;++i){
		for (int j=1;j<=maxn;++j){
			s[i][j]=s[i][j-1]+(g[j]==i);
		}
	}
	int q;
	cin>>q;
	while(q--){
		int l,r,k;
		cin>>l>>r>>k;
		cout<<s[k][r]-s[k][l-1]<<endl;
	}
	return 0;
}