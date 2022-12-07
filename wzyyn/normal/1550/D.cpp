#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=200005;
const int mo=1000000007;

int n,t,l,r,ans;

struct node{
	int T,x,y;
	bool operator <(const node &a)const{
		return T<a.T;
	}
}q[2*N];
int fac[N],inv[N];
void init(){
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<N;i++) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<N;i++) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	for (int i=1;i<N;i++) fac[i]=1ll*fac[i-1]*i%mo;
}
int V(int x,int y){
	if (x<0||y<0) return 0;
	return 1ll*fac[x+y]*inv[x]%mo*inv[y]%mo;
}
void solve(){
	t=0; ans=0;
	scanf("%d%d%d",&n,&l,&r);
	for (int i=1;i<=n;i++){
		int d1=i-l,d2=r-i;
		if (d1<=d2){
			q[++t]=(node){d1+1,3,1};
			q[++t]=(node){d2+1,1,0};
		}
		else{
			q[++t]=(node){d2+1,3,2};
			q[++t]=(node){d1+1,2,0};
		}
	}
	q[0].T=1;
	sort(q+1,q+t+1);
	int s[4]={0,0,0,n};
	for (int i=1;i<=t;i++){
		if (q[i].T!=q[i-1].T){
			if (s[0]) break;
			int w=V(n/2-s[1],n-n/2-s[2]);
			if (n&1) w=w+V(n-n/2-s[1],n/2-s[2]);
			//cout<<s[1]<<' '<<s[2]<<' '<<w<<endl;
			ans=(ans+1ll*w*(q[i].T-q[i-1].T))%mo;
		}
		--s[q[i].x];
		++s[q[i].y];
	}
	cout<<ans<<endl;
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}