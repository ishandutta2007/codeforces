#include<iostream>
#include<cstdio>
using namespace std;
const long long N=100005,mod=1e9+7;
long long n,k;
inline long long ksm(long long a,long long b){
	long long t=1,y=a;
	while (b){
		if (b&1) t=(long long)t*y%mod;
		y=(long long)y*y%mod;
		b>>=1;
	}
	return t;
}
int main(){
	cin>>n>>k;
	if(k==0){
		cout<<ksm(n,n-1)<<endl;
	}else if(k==1){
		cout<<ksm(n,n)<<endl;
	}else{
		long long sum=0;
		for(long long i=1;i!=1||sum==0;i=i*k%n)sum++;
		cout<<ksm(n,(n-1)/sum)<<endl;
	}
}//longlong