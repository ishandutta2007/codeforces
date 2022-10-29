#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
#define N 100010
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;i++)

LL a,b; 
int p1[N],p2[N];

int main(){
	cin>>a>>b;
	LL k=long(sqrt(a+b)*2);
	while(k*(k+1)/2>a+b)k--;
	int sum1=0,x;
	for(x=k;x;x--){
		if(sum1+x>a)break;
		sum1+=x;
	}
	if(x==0){
		cout<<k<<endl;
		rep(i,1,k)cout<<i<<" ";
		cout<<endl<<0<<endl<<endl;
	}else if(sum1<a){
		cout<<k-x+1<<endl;
		cout<<a-sum1;
		rep(i,x+1,k)cout<<" "<<i;
		cout<<endl<<max(0,x-1)<<endl;
		rep(i,1,x)if(i!=a-sum1)cout<<i<<" ";
		cout<<endl;
	}else{
		cout<<k-x<<endl;
		rep(i,x+1,k)cout<<i<<" ";
		cout<<endl<<x<<endl;
		rep(i,1,x)cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}