#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(a[1]+a[2]<=a[n])
			printf("%d %d %d\n",1,2,n);
		else puts("-1");
	}
	return 0;
}