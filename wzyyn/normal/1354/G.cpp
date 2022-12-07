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
int n,k,B=25;
int cmp(int i,int j,int l){
	cout<<"? "<<l<<' '<<l<<endl;
	For(p,i,i+l-1) cout<<p<<' '; cout<<endl;
	For(p,j,j+l-1) cout<<p<<' '; cout<<endl;
	string s;
	cin>>s;
	if (s=="WASTED") exit(0);
	if (s=="FIRST") return 1;
	if (s=="EQUAL") return 0;
	if (s=="SECOND") return -1;
	assert(0);
}
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,B){
		int p=(rand()%(n-1)+2);
		if (cmp(1,p,1)==-1)
			return cout<<"! "<<1<<endl,void(0);
	}
	int p=1;
	for (;p<=n;p*=2){
		int r=min(n-p,p);
		if (cmp(1,p+1,r)==0) continue;
		int l=1,ans=r;
		while (l<=r){
			int mid=(l+r)/2;
			if (cmp(1,p+1,mid))
				ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<"! "<<p+ans<<endl;
		return;
	}
}
int main(){
	srand(time(NULL));
	int T;
	scanf("%d",&T);
	while (T--) solve();
}