#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int mo=1000000007;
const int N=200005;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int n,k,mu[N];
vector<int> di[N];
int solve1(){
	int ans=0;
	For(i,1,n-1) ans=(ans+power(k,mo-1-i))%mo;
	return ans;
}
int solve2(){
	int ans=0; mu[1]=1;
	For(i,1,N-1) For(j,2,(N-1)/i) mu[i*j]-=mu[i];
	For(i,1,N-1) For(j,1,(N-1)/i) di[i*j].PB(i);
	For(i,2,2*n-2){
		int l=max(1,i-(n-1));
		int r=min(n-1,i-1);
		For(j,0,di[i].size()-1){
			if (2*di[i][j]==i) continue;
			int nl=(l-1)/di[i][j]+1;
			int nr=r/di[i][j];
			if (nl>nr) continue;
			int val=di[i][j],cnt=0;
			int res=i/di[i][j];
			For(k,0,di[res].size()-1){
				int v=di[res][k];
				if (!mu[v]) continue;
				int nnl=(nl-1)/v+1;
				int nnr=nr/v;
				if (nnl<=nnr)
					cnt+=mu[v]*(nnr-nnl+1);
			}
			int tms=max(i-n,val);
			ans=(ans+1ll*power(k,tms)*cnt)%mo;
		}
	}
	ans=1ll*ans*power(k,mo-1-n)%mo;
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	int ans=(solve1()+solve2())%mo;
	printf("%d\n",ans);
}