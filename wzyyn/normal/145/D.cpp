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
int n,a[N],q[N],nxt[N];
map<int,int> mp;
set<int> S;
bool check(int x){
	for (;x;x/=10)
		if (x%10!=4&&x%10!=7)
			return 0;
	return 1;
}
int main(){
	q[++*q]=0;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) if (check(a[i])) q[++*q]=i;
	ll ans=1ull*(n+2)*(n+1)/2*(n)/3*(n-1)/4;
	//cout<<ans<<endl;
	Rep(i,*q,1) nxt[i]=mp[a[q[i]]],mp[a[q[i]]]=i;
	For(i,2,(*q)-1){
		S.clear();
		S.insert(q[i]);
		S.insert(n+1);
		ll cur=0,L=q[i+1]-q[i];
		Rep(j,i,2){
			for (int k=nxt[j];k>i;k=nxt[k]){
				set<int>::iterator pre,nxt;
				pre=nxt=S.insert(q[k]).fi;
				int pr=*(--pre),nx=*(++nxt);
				if (pr!=q[i]) cur+=1ll*L*(q[k]-pr)*(nx-q[k]);
				else cur+=(1ll*L*(L+1)/2+1ll*L*(q[k]-pr-L))*(nx-q[k]);
				//cout<<pr<<' '<<nx<<' '<<L<<' '<<q[k]<<endl;
			}
			//cout<<i<<' '<<j<<' '<<cur<<endl;
			ans-=1ll*cur*(q[j]-q[j-1]);
		} 
	}
	printf("%lld\n",ans);
}