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
const int N=200005;
int n,k,mod,q1,q2,ans;
int inv[N],cnt[N];
void solve(int l,int r,int d){
	if (d==1||l==r){
		int len=r-l+1;
		q1&&q1!=len?q2=len:q1=len;
		ans=(ans+1ll*len*(len-1)/2%mod*(mod+1)/2)%mod;
		cnt[len]++;
		return;
	}
	int mid=(l+r)/2;
	solve(l,mid,d-1);
	solve(mid+1,r,d-1);
}
int main(){
	scanf("%d%d%d",&n,&k,&mod);
	inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
	For(i,1,N-1) inv[i]=(inv[i]+inv[i-1])%mod;
	solve(1,n,k);
	//cout<<q1<<' '<<q2<<' '<<cnt[q1]<<' '<<cnt[q2]<<endl;
	For(i,1,q1){
		int val=1ll*(i-1)*cnt[q1]%mod*(mod+1)/2%mod;
		ans=(ans+1ll*(cnt[q1]-1)*(inv[i+q1]+mod-inv[i])%mod*val)%mod;
		ans=(ans+1ll*(cnt[q2]-0)*(inv[i+q2]+mod-inv[i])%mod*val)%mod;
	}
	For(i,1,q2){
		int val=1ll*(i-1)*cnt[q2]%mod*(mod+1)/2%mod;
		ans=(ans+1ll*(cnt[q1]-0)*(inv[i+q1]+mod-inv[i])%mod*val)%mod;
		ans=(ans+1ll*(cnt[q2]-1)*(inv[i+q2]+mod-inv[i])%mod*val)%mod;
	}
	printf("%d\n",ans);
}
/*
(j-1)/2/(i+j)
*/