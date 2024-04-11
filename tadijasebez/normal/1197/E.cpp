#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int inf=1e9+9;
int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
#define node pair<int,int>
#define mnx first
#define cnt second
node operator + (node a,node b){if(a.mnx>b.mnx)swap(a,b);return a.mnx==b.mnx?(node){a.mnx,add(a.cnt,b.cnt)}:a;}
const int N=200050;
node fen[N]={{inf,0}};
void Add(int i,node f){for(;i<N;i+=i&-i)fen[i]=fen[i]+f;}
node Get(int i){node ans={0,1};for(;i;i-=i&-i)ans=ans+fen[i];return ans;}
int mn[N],dp[N];
#define doll pair<int,int>
#define out first
#define in second
doll a[N];
int main(){
	int n;
	scanf("%i",&n);
	int mxi=0;
	for(int i=1;i<=n;i++)scanf("%i %i",&a[i].out,&a[i].in),mxi=max(mxi,a[i].in);
	sort(a+1,a+1+n);
	node ans={inf,0};
	for(int i=1;i<=n;i++){
		int j=upper_bound(a+1,a+1+n,(doll){a[i].in,inf})-a-1;
		node f=Get(j);
		f.mnx+=a[i].in;
		mn[i]=f.mnx;
		dp[i]=f.cnt;
		f.mnx-=a[i].out;
		Add(i,f);
		if(a[i].out>mxi)
			ans=ans+(node){mn[i],dp[i]};
	}
	printf("%i\n",ans.cnt);
	return 0;
}