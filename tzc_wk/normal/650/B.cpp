#include <bits/stdc++.h>
using namespace std;
#define REP(i,n)	for((i)=0;(i)<(n);(i)++)
typedef long long ll;
const int MAXN=5e5+100; 
int n,a,b,t;
ll sum[MAXN];
char s[MAXN];
ll check(int L,int R){
	return (ll)(min(L,R)+L+R)*a+(sum[R+1]-sum[n-L]+sum[n]);
}
int main(){
	int i;
	cin>>n>>a>>b>>t>>s;
	REP(i,n) sum[i+1]=sum[i]+((s[i]=='w')?b+1:1);
	int ans=0;
	for(int l=0;l<n;l++){
		if(check(l,0)>t)	continue;
		int low=0,high=n-l;
		while(high-low>1){
			int mid=(low+high)/2;
			if(check(l,mid)<=t)	low=mid;
			else	high=mid;
		}
		ans=max(ans,l+low+1);
	}
	cout<<ans<<endl;
	return 0;
}