#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N=200005;
int n,a,b,k,divide[N],st[N],tp,sum;char s[N];
int res[N],rtp;
int main(){
	scanf("%d%d%d%d",&n,&a,&b,&k);scanf("%s",s+1);
	for(int i=1;i<=n;i++)if(s[i]=='1')st[++tp]=i;st[++tp]=n+1;int last=1;
	for(int i=1;i<=n+1;i++)if(st[i]>st[i-1]+1)sum+=(st[i]-st[i-1]-1)/b;
	while (last<=n+1&&st[last]-st[last-1]-1<b) last++;
	while (sum>=a&&last<=n+1){
		st[last-1]+=b; sum--; res[++rtp]=st[last-1];
		while (last<=n+1&&st[last]-st[last-1]-1<b) last++;
	}
	printf("%d\n",rtp);
	for (int i=1;i<=rtp;i++) printf("%d ",res[i]);
	return 0;
}