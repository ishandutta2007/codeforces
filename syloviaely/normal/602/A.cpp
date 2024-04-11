#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
long long read(){
	int n,m; scanf("%d%d",&n,&m);
	long long ans=0;
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1); ans=ans*m+k1;
	}
	return ans;
}
int main(){
	long long k1=read(),k2=read();
	if (k1==k2) cout<<"="<<endl; else if (k1<k2) cout<<"<"<<endl; else cout<<">"<<endl;
	return 0;
}