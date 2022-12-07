#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
int n,x,vis[N],q[N];
int cnt[N],mu[N];
vector<int> di[N];
ll ans;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void init(){
	mu[1]=1;
	For(i,1,N-1)
		For(j,2,(N-1)/i)
			mu[i*j]-=mu[i];
	For(i,1,N-1)
		For(j,1,(N-1)/i)
			di[i*j].PB(i);
}
void solve(int v){
	int m=(N-1)/v; *q=0;
	For(i,1,m) cnt[i]=0;
	For(i,1,(N-1)/v)
		if (vis[i*v]){
			q[++*q]=i;
			++cnt[i];
		}
	//cout<<v<<' '<<*q<<endl;
	if (!*q) return;
	For(i,1,m) For(j,2,m/i)
		cnt[i]+=cnt[i*j];
	int h=1,t=*q;
	//cout<<v<<' '<<*q<<endl;
	for (;h<=t;--t){
		int sum=0;
		for (auto i:di[q[t]])
			sum+=mu[i]*cnt[i];
		for (;;){
			int v=(gcd(q[h],q[t])==1);
			if (sum-v<=0) break;
			for (auto i:di[q[h]]) --cnt[i];
			sum-=v; ++h;
		}
		//cout<<h<<' '<<t<<' '<<q[h]<<' '<<q[t]<<' '<<v<<' '<<sum<<endl;
		if (sum)
			ans=max(ans,1ll*v*q[h]*q[t]);
		for (auto i:di[q[t]]) --cnt[i];
	}
}
int main(){
	init();
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&x),vis[x]=1;
	For(i,1,N-1) solve(i);
	printf("%lld\n",ans);
}