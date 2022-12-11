#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,s,e,h[N],a[N],b[N],c[N],d[N];
long long calc(int x,int y){
	if(x<y)return 0ll+h[y]-h[x]+d[x]+a[y];
	else return 0ll+h[x]-h[y]+c[x]+b[y];
}
priority_queue<long long,vector<long long>,greater<long long>>q;
long long ans;
int main(){
	scanf("%d%d%d",&n,&s,&e);
	for(int i=1;i<=n;i++)scanf("%d",&h[i]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	if(s==1||e==1)ans=calc(s,e);
	else ans=calc(s,1)+calc(1,e);
	for(int i=2;i<=n;++i){
		long long A=h[i]+a[i],B=-h[i]+b[i],C=h[i]+c[i],D=-h[i]+d[i];
		if(i==s)q.push(D-C);
		else if(i==e)q.push(B-A);
		else{
			ans+=A+C;
			if(i<s)q.push(B-A);
			if(i<e)q.push(D-C);
			ans+=q.top(),q.pop();
			if(i>s)q.push(B-A);
			if(i>e)q.push(D-C);
		}
	}
	printf("%lld",ans);
	return 0;
}