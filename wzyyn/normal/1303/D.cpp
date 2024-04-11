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

map<int,int> mp;
ll n,tmp;
int m,S[105];
void solve(){
	tmp=0;
	scanf("%lld%d",&n,&m);
	memset(S,0,sizeof(S));
	For(i,1,m){
		int x;
		scanf("%d",&x);
		++S[mp[x]]; tmp+=x;
	}
	if (tmp<n)
		return puts("-1"),void(0);
	ll S1=0,S2=0,ans=0;
	For(i,0,60){
		if (n&(1ll<<i)) S1+=1ll<<i;
		S2+=(1ll<<i)*S[i];
		//cout<<S1<<' '<<S2<<' '<<i<<endl;
		if (S2<S1){
			int p=i+1;
			for (;!S[p];++p); --S[p];
			//cout<<"INFO "<<' '<<p<<endl;
			For(j,i,p-1) S[j]++,ans++;
			S[i]++; S2+=(1ll<<i)*2;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	For(i,0,29) mp[1<<i]=i;
	int T;
	scanf("%d",&T);
	while (T--) solve();
}