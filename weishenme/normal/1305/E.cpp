#include<bits/stdc++.h>
using namespace std;
int a[5005],n,val[5005],m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i/2;j++)val[i]+=i-j-j;
	for (int i=n;i>=0;i--)
		if (val[i]<=m){
			m-=val[i];
			if (m>=i/2&&m){
				puts("-1");
				return 0;
			}
			if (n==i&&m>0){
				puts("-1");
				return 0;
			}
			for (int j=1;j<=i;j++)printf("%d ",j);
			if (m)printf("%d ",i+i-2*m+1),i++;
			for (int j=i+1;j<=n;j++)printf("%d ",20000*j+100000000);
			return 0;
		}
	puts("-1");
}