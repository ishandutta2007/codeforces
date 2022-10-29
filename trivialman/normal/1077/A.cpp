#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
#define N 300000
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define CL(x) memset(x,0,sizeof(x))

int main(){
	int t;
	cin>>t;
	while(t--){
		LL a,b,k;
		cin>>a>>b>>k;
		if(k%2==0){
			cout<<(a-b)*(k/2)<<endl;
		}else{
			cout<<(a-b)*(k/2)+a<<endl;
		}
	}
	return 0;
}