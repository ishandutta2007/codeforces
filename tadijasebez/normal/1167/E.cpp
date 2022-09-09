#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000050;
int sum[N];
void Set(int i,int f){for(;i<N;i+=i&-i)sum[i]+=f;}
int Get(int i){int ans=0;for(;i;i-=i&-i)ans+=sum[i];return ans;}
int a[N];
bool ok[N];
pair<int,int> b[N];
int c[N];
int main(){
	int n,x;
	scanf("%i %i",&n,&x);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),b[a[i]].second=i;
	for(int i=n;i>=1;i--)b[a[i]].first=i;
	b[0]={1,1};b[x+1]={n+1,n+1};
	//for(int i=1;i<=x;i++)if(b[i].first==0)b[i]={b[i-1].second,b[i-1].second};
	a[0]=1;a[n+1]=x;
	ok[0]=1;
	int mx=1;
	c[0]=1;
	for(int i=1;i<=x;i++){
		ok[i]=ok[i-1]&(b[i].first>=mx || b[i].first==0);
		mx=max(mx,b[i].second);
		c[i]=mx;
	}
	for(int i=0;i<=x;i++)if(ok[i])Set(c[i],1);
	ll ans=0;
	for(int i=x,mn=n+1;i>=1;i--){
		if(ok[i])Set(c[i],-1);
		ans+=Get(mn);
		if(b[i].second>mn && b[i].second!=0)break;
		if(b[i].first)mn=b[i].first;
	}
	printf("%lld\n",ans);
	return 0;
}