#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector> 
using namespace std;
//#define N 300000
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define CL(x) memset(x,0,sizeof(x))

int main(){
	LL n,k;
	cin>>n>>k;
	LL ans=(n*2+k-1)/k+(n*5+k-1)/k+(n*8+k-1)/k;
	cout<<ans<<endl;
	return 0;
}