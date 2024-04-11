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
		if(n==1){
			puts("1");
			continue;
		}
		if(n==3){
			puts("2");
			continue;
		}
		int ans=1e9;
		for(int i=3;i<=5000;i++)
			if(n<=1ll*i*(i+1)/2)
				ans=min(ans,i+(i*(i+1)/2==n+1? 1:0));
		printf("%d\n",ans);
	}
	return 0;
}