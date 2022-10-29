#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
//#define N 100010
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define CL(x) memset(x,0,sizeof(x))


int n;
LL l,r;

LL calc(LL x){
	return x%2?-(x/2)-1:x/2;
}

int main(){
	cin>>n;
	rep(i,1,n){
		cin>>l>>r;
		cout<<calc(r)-calc(l-1)<<endl;
	}
	return 0;
}