#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

int n;
pair<int,int> a[500005];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
	sort(a+1,a+n+1);
	long long ans=0;
	for (int i=1;i<=n;i++)
		ans+=a[i].second;
	int mx=0;
	for (int i=2;i<=n;i++){
		mx=max(mx,a[i-1].first+a[i-1].second);
		if (mx<a[i].first) ans+=a[i].first-mx;
	}
	cout<<ans<<endl;
}