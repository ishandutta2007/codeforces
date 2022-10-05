#include<bits/stdc++.h>
using namespace std;
int t[1100000];//
int a[1<<21]={};
int b[1<<21]={};
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		t[i]=x;
		b[x]=a[x];
		a[x]=i;
	}
	for(int i=0;i<21;i++){
		for(int j=0;j<(1<<21);j++){
			if(j&(1<<i)){
				if(a[j]<a[j^(1<<i)]) b[j^(1<<i)]=max(a[j],b[j^(1<<i)]);
				else{
					b[j^(1<<i)]=max(a[j^(1<<i)],b[j]);
					a[j^(1<<i)]=a[j];
				}
			}
		}
	} 
	int maxx=0;
	for(int i=1;i<=n-2;i++){
		int u=0;
		for(int j=20;j>=0;j--){
			if(t[i]&(1<<j)) continue;
			if(b[u^(1<<j)]>i) u^=(1<<j);
		}
		maxx=max(maxx,u|t[i]);
	}
	printf("%d",maxx);
	return 0;
}