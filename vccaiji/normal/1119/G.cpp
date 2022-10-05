#include<bits/stdc++.h>
using namespace std;
int hp[1100000];
int num[1100000]={};
int s[1100000];
int tot=0;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&hp[i]);
	hp[0]=0;
	for(int i=2;i<=m;i++) hp[i]+=hp[i-1];
	hp[m]=((hp[m]+n-1)/n)*n;
	printf("%d\n",hp[m]/n);
	for(int i=1;i<m;i++) num[hp[i]%n]++;
	num[n]++;
	for(int i=0,j=0;i<=n;){
		if(num[i]){
			num[i]--;
			s[++tot]=i-j;
			j=i;
		}
		else i++;
	}
	for(int i=1;i<=m;i++) printf("%d ",s[i]);
	printf("\n");
	int ii=1,now=0;
	for(int j=1;j<=hp[m]/n;j++){
		for(int jj=1;jj<=m;jj++){
			now+=s[jj];
			while(now>hp[ii]) ii++;
			printf("%d ",ii);
		}
		printf("\n");
	}
	return 0;
}