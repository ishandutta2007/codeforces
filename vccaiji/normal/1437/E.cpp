#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 100000000000ll
int n,k;
int a[510000];
int b[510000];
bool c[510000];
int o[510000];
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)a[i]-=i;
	a[0]=-INF/2,a[n+1]=INF/2;
	for(int i=1;i<=k;i++)cin>>b[i];
	for(int i=1;i<=k;i++)c[b[i]]=1;
	int ans=0;bool r=1;
	int l=n+1;
	for(int i=n;i>=0;i--){
		if(i==0||c[i]){
			if(a[l]<a[i]){
				r=0;
				break;
			}
			o[0]=a[l];
			for(int j=1;j<=l-i;j++)o[j]=-INF;
			for(int j=l-1;j>=i+1;j--){
				int ll=0,rr=l-i+1;
				for(;ll<rr;){
					int md=(ll+rr)/2;
					if(o[md]<a[j])rr=md;
					else ll=md+1;
				}
				if(ll)o[ll]=a[j];
			}
			ans+=l-i;
			for(int j=0;j<=l-i;j++){
				if(o[j]>=a[i])ans--;
			}
			l=i;
		}
	}
	if(r==0){
		cout<<-1;return 0;
	}
	cout<<ans;
	return 0;
}