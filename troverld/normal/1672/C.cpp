#include<bits/stdc++.h>
using namespace std;
int T,n,a[200100];
void mina(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int l=1;while(l<n&&a[l]!=a[l+1])l++;
	int r=n;while(r>1&&a[r]!=a[r-1])r--;
	if(l==n&&r==1){puts("0");return;}
	if(l+1==r){puts("0");return;}
	if(l+2==r){puts("1");return;}
	printf("%d\n",r-l-2);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}