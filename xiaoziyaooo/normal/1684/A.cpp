#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n<100)
			printf("%d\n",n%10);
		else{
			int ans=10;
			while(n)
				ans=min(ans,n%10),n/=10;
			printf("%d\n",ans);
		}
	}
	return 0;
}