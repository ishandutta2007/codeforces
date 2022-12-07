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
#define y1 fdhjksa
using namespace std;
const int N=100005;
int n,k;
int mn[N];
map<int,int> mp;
ll ans;
void init(){
	mn[1]=1;
	For(i,2,N-1) if (!mn[i])
		For(j,1,(N-1)/i) if (!mn[i*j]) mn[i*j]=i;
}
int main(){
	init();
	scanf("%d%d",&n,&k);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		int tmp=x;
		ll val=1,fl=1,las=-1,cnt=0;
		for (;x!=1;x/=mn[x]){
			if (mn[x]!=las){
				if (las!=-1){
					For(j,1,cnt/k*k)
						tmp/=las;
					for (;cnt%k!=0;++cnt){
						val*=las;
						if (val>=N) fl=0;
					}
				}
				las=mn[x];
				cnt=0;
			}
			++cnt;
		}
		For(j,1,cnt/k*k)
			tmp/=las;
		for (;cnt%k!=0;++cnt){
			val*=las;
			if (val>=N) fl=0;
		}
		//printf("%lld %lld %lld\n",val,tmp,las);
		if (fl)
			ans+=mp[val];
			++mp[tmp];
	}
printf("%lld\n",ans);
}