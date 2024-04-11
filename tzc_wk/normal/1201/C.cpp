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
#define MAKE1(a)	int a;
#define MAKE2(a,b)	int a,b;
#define MAKE3(a,b,c) int a,b,c;
#define MAKE4(a,b,c,d) int a,b,c,d;
#define DR1(a)		MAKE1(a);cin>>a;
#define DR2(a,b)	MAKE2(a,b);cin>>a>>b;
#define DR3(a,b,c)	MAKE3(a,b,c);cin>>a>>b>>c;
#define DR4(a,b,c,d) MAKE4(a,b,c,d);cin>>a>>b>>c>>d;
#define int long long
int a[200005],n,k,ans;
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(n==1)	return cout<<(int)a[1]+k<<endl,0;
	sort(a+1,a+n+1);
	int mid=(n+1)/2,cur=mid,sum=0;
	ans=a[mid];
	while(k){
		if(cur==n){
			ans+=k/(n-mid+1);
			break;
		}
		if(a[cur+1]!=a[cur]){
			int next=k-(cur-mid+1)*(a[cur+1]-a[cur]);
			if(next<0){
				ans+=k/(cur-mid+1);
				break;
			}
			else	k=next;
		}
		cur++;
		ans=a[cur];
	}
	cout<<ans<<endl;
	return 0;
}//