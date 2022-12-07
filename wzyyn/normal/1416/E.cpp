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

const int N=500005;
int n,a[N];
set<pll> One;
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	//a[0]=1<<30;
	int ans=0,two=-1;
	ll sgn=1,key=0;
	One.clear();
	For(i,1,n){
		if (two!=-1){
			ans+=2;
			sgn=1; key=0;
			One.clear();
			if (two<a[i])
				One.insert(pll(a[i]-two,a[i]-two));
			two=-1;
		}
		else if (!One.empty()){
			++ans;
			if (sgn==-1){
				ll lim=key-a[i];
				for (;!One.empty();){
					pll tmp=*One.begin();
					One.erase(One.begin());
					if (tmp.se<=lim);
					else{
						if (tmp.fi<=lim)
							tmp.fi=lim+1;
						One.insert(tmp);
						break;
					}
				}
			}
			else{
				ll lim=a[i]-key;
				for (;!One.empty();){
					pll tmp=*One.rbegin();
					One.erase(tmp);
					if (tmp.fi>=lim);
					else{
						if (tmp.se>=lim)
							tmp.se=lim-1;
						One.insert(tmp);
						break;
					}
				}
			}
			key=a[i]-key;
			sgn*=-1;
		}
		else{
			sgn=-1; key=a[i];
			int lim=min(a[i-1]-1,a[i]-1);
			if (lim>=1) One.insert(pll(1,lim));
		}
		two=-1;
		if (a[i]%2==0){
			int y=a[i]/2;
			ll p=(y-key)/sgn;
			auto it=One.lower_bound(pll(p+1,-(1ll<<60)));
			bool flag=0;
			if (it!=One.begin()){
				--it;
				if (it->fi<=p&&p<=it->se)
					flag=1;
			}
			if (flag) two=y;
			else One.insert(pll(p,p));
		}
		//cout<<i<<'='<<ans<<endl;
	}
	if (two!=-1) ans+=2;
	else if (!One.empty()) ans++;
	printf("%d\n",2*n-ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}