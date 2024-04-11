#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T;
long long ans;
int a[maxn],b[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=2;i<=n;i++){
			if(abs(a[i]-a[i-1])+abs(b[i]-b[i-1])>abs(a[i]-b[i-1])+abs(b[i]-a[i-1]))
				swap(a[i],b[i]);
			ans+=abs(a[i]-a[i-1])+abs(b[i]-b[i-1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}