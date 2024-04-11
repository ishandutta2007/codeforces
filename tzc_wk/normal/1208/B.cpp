#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD			1000000007
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
int n,a[2005],b[2005],c[2005],cnt;
bool p[2005];
inline bool check(int len){
	for(int i=1;i<=n-len+1;i++){
		memset(p,0,sizeof(p));
		bool flag=1;
		for(int j=1;j<i;j++){
			if(p[a[j]])	flag=0;
			p[a[j]]=1;
		}
		for(int j=i+len;j<=n;j++){
			if(p[a[j]])	flag=0;
			p[a[j]]=1;
		}
		if(flag)	return 1;
	}
	return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i],b[i]=a[i];
	sort(b+1,b+1+n);
	for(int i=1;i<=n+1;i++){
		if(b[i]!=b[i-1])	c[++cnt]=b[i-1];
	}
	for(int i=1;i<=n;i++)	a[i]=lower_bound(c+1,c+1+cnt,a[i])-c-1;
	int l=0,r=n,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))	ans=mid,r=mid-1;
		else			l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}