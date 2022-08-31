#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
long long x,s;
vector<long long>A;
int main(){
	scanf("%I64d%I64d",&s,&x);
	if (x==0){
		if ((s%2)==0) cout<<1<<endl; else cout<<0<<endl;
		return 0;
	}
	int flag=0;
	if (s==x) flag=-2;
	long long ans=1;
	for (int i=50;i>=0;i--)
		if (x&(1ll<<i)) s-=(1ll<<i),ans*=2;
		else A.push_back(1ll<<i+1);
	if (s<0){
		cout<<0<<endl; return 0;
	}
	for (int i=0;i<A.size();i++) if (s&A[i]) s-=A[i];
	if (s==0) cout<<ans+flag<<endl; else cout<<0<<endl;
	return 0;
}