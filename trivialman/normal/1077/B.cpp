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

int n,a[110];

int main(){
	cin>>n;
	rep(i,1,n)cin>>a[i];
	int cnt=0;
	rep(i,2,n-1){
		if(a[i]==0&&a[i-1]==1&&a[i+1]==1){
			++cnt;a[i+1]=0;
		}
	}
	cout<<cnt<<endl;
	return 0;
}