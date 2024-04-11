#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(i+j<=n)m--;
	m=-m;
	if(m<0){
		cout<<-1;
		return 0;
	}
	int N=6*n+10;
	int now=0;
	for(int i=1;i<=n;i++)a[i]=i;
	for(int i=n;i>=1;i--){
		if(now==m) break;
		if(m-now>=(i-1)/2){
			now+=(i-1)/2;
			a[i]=N*i-1;
			continue;
		}
			int j=m-now;
			a[i]=i+2*j;
			break;
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}