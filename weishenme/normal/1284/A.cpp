#include<bits/stdc++.h>
using namespace std;
const int M=998244353,N=1005;
int n,m,q,x;
char s1[N][N],s2[N][N];
int ksm(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=x*x%M)
		if (y&1)(ans*=x)%=M;
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)scanf("%s",s1[i]);
	for (int i=0;i<m;i++)scanf("%s",s2[i]);
	scanf("%d",&q);
	while (q--){
		scanf("%d",&x);
		x--;
		printf("%s%s\n",s1[x%n],s2[x%m]);
	}
}