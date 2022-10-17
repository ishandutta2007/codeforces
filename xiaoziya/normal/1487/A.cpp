#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int now=1;
		while(now<=n&&a[now]==a[1])
			now++;
		printf("%d\n",n-now+1);
	}
	return 0;
}