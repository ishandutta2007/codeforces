#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e5+5;
int n,a[N],b[N];
long long s1[N],s2[N];
void solve(){
	n=in();
	long long sum=0,ans=0;
	for(int i=1;i<=n;i++)a[i]=in();
	for(int i=1;i<=n;i++)b[i]=in(),sum+=b[i];
	vector<int> v1,v2;
	for(int i=1;i<=n;i++){
		if(!a[i])v1.push_back(b[i]);
		else v2.push_back(b[i]);
	}
	sort(v1.begin(),v1.end(),greater<int>());
	sort(v2.begin(),v2.end(),greater<int>());
	int m1=v1.size(),m2=v2.size();
	for(int i=1;i<=m1;i++)s1[i]=s1[i-1]+v1[i-1];
	for(int i=1;i<=m2;i++)s2[i]=s2[i-1]+v2[i-1];
	if(m2)ans=s1[min(m2-1,m1)]+s2[min(m1,m2)];
	if(m1)ans=max(ans,s2[min(m1-1,m2)]+s1[min(m1,m2)]);
	printf("%lld\n",ans+sum);
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}