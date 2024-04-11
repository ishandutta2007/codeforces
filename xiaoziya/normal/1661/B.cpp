#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int a[maxn],b[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=1e9;
		int mul=1;
		for(int i=0;i<=16;i++){
			int val=(32768-n)%32768,v=i;
			v+=val/mul,val%=mul;
			ans=min(ans,v+__builtin_popcount(val));
			n=(n<<1)%32768,mul<<=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}