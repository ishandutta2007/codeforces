#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		ans=flg=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int lst=n+1;
		for(int i=n;i>=1;i--)
			if(1ll*(lst-i)*a[i]>=m)
				lst=i,ans++;
		printf("%d\n",ans);
	}
	return 0;
}