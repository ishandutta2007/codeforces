#include<bits/stdc++.h>
using namespace std;
bool is_prime[1100000];
int t[1100000];
int a[1100000]={};
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		if(t[i]<=m) a[t[i]]++;
	}
	for(int i=2;i<=m;i++) is_prime[i]=true;
	for(int i=2;i<=m;i++){
		if(is_prime[i]){
			int t=m/i;
			for(int j=i;j<=t;j++) is_prime[i*j]=false;
			for(int j=1;j<=t;j++) a[i*j]+=a[j]; 
		}
	}
	int maxx=a[1],ii=1;
	for(int i=2;i<=m;i++) {
		if(maxx<a[i]){
			ii=i;
			maxx=a[i];
		}
	}
	printf("%d %d\n",ii,maxx);
	for(int i=1;i<=n;i++) {
		if(ii%t[i]==0) printf("%d ",i);
	}
	return 0;
}