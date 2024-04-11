#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N 100010
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;i++)

int n,m,k;
int a[N],b[N],t[N]; 

int main(){
	cin>>n;
	rep(i,1,n-1)cin>>a[i];
	rep(i,1,n-1)cin>>b[i];
	bool flag=false;
	for(int t0=0;t0<=3;t0++){
		t[1]=t0;flag=true;
		rep(i,2,n){
			t[i]=0;
			if(t[i-1]&1)t[i]+=(b[i-1]&1);else t[i]+=(a[i-1]&1);
			if(t[i-1]&2)t[i]+=(b[i-1]&2);else t[i]+=(a[i-1]&2);
			//cout<<a[i]<<" "<<t[i-1]<<" "<<t[i]<<endl;
			if((t[i]&t[i-1])!=b[i-1]||(t[i]|t[i-1])!=a[i-1]){
				flag=false;
				break;
			}
		}
		if(flag)break;
	}
	if(!flag){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
		rep(i,1,n)cout<<t[i]<<" ";
		cout<<endl;
	}
	return 0;
}