#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;	
}
const int N=2e5+5;
int n,q;
int a[N],t[N];
long long sum;
int main(){
	n=in(),q=in();
	for(int i=1;i<=n;i++)a[i]=in(),t[i]=0,sum+=a[i];
	int pre=0,now=0;
	for(int i=1;i<=q;i++){
		int opt=in();
		if(opt==1){
			int p=in(),v=in();
			sum-=t[p]<pre?now:a[p];
			a[p]=v,t[p]=i;
			sum+=v;	
		}else{
			pre=i,now=in();
			sum=1ll*now*n;	
		}
		printf("%lld\n",sum);
	}
	return 0;
}