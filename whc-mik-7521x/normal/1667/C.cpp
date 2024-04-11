#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main(){
	int n,ans;
	scanf("%d", &n);
	if(n==1)return printf("%d\n%d %d",1,1,1),0;
	ans=(2*n+1)/3;
	printf("%d\n",(2*n+1)/3);
	if(n%3==0)n-=1,ans-=1,printf("%d %d\n",n+1,n+1);
	if(n%3==1)n-=2,ans-=2,printf("%d %d\n%d %d\n",n+1,n+1,n+2,n+2);
	for(int i=1;i<=(ans+1)>>1;i++)printf("%d %d\n",i,(ans+1)/2+1-i);
	for(int i=1;i<=(ans)>>1;i++)printf("%d %d\n",(ans+1)/2+i,ans+1-i);
	return 0;
}