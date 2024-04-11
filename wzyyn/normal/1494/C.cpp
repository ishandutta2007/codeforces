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

const int N=200005;
int n,m,s[N],a[N],b[N],ans;
int solve(vector<int> v1,vector<int> v2){
	if (!v1.size()||!v2.size()) return 0;
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int n=v1.size(),m=v2.size();
	For(i,0,n-1){
		int p=lower_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
		if (p!=m&&v2[p]==v1[i]) s[i]=1;
		else s[i]=0;
	}
	s[n]=0;
	Rep(i,n-1,0) s[i]+=s[i+1];
	int mx=0;
	For(i,0,v2.size()-1){
		int l=0,r=n-1,ans=n;
		while (l<=r){
			int mid=(l+r)/2;
			if (v1[mid]-mid>v2[i])
				ans=mid,r=mid-1;
			else l=mid+1;
		}
		int p1=lower_bound(v2.begin(),v2.end(),v2[i])-v2.begin();
		int p2=lower_bound(v2.begin(),v2.end(),v2[i]+ans)-v2.begin();
		mx=max(mx,p2-p1+s[ans]);
	}
	return mx;
}
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,m) scanf("%d",&b[i]);
	
	vector<int> v1,v2;
	For(i,1,n) if (a[i]<0) v1.PB(-a[i]);
	For(i,1,m) if (b[i]<0) v2.PB(-b[i]);
	int ans=solve(v1,v2);
	
	v1.resize(0);
	v2.resize(0);
	For(i,1,n) if (a[i]>0) v1.PB(a[i]);
	For(i,1,m) if (b[i]>0) v2.PB(b[i]);
	cout<<ans+solve(v1,v2)<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}