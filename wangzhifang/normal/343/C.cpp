#include<bits/stdc++.h>
#define max_n 100000
#define lls "%I64d"
using namespace std;
int n,m;
long long h[max_n+1],p[max_n+1];
int judge(long long x){
	long long tim;
	for(int i=0,idx=1; ++i<=n; ){
		if(h[i]-p[idx]>x)
			return 0;
		for(tim=p[idx]>=h[i]?x:max((x-(h[i]-p[idx]))>>1,x-(h[i]-p[idx])*2); idx<=m&&p[idx]<=tim+h[i]; ++idx);
		if(idx>m)
			return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0; ++i<=n; scanf(lls,h+i));
	for(int i=0; ++i<=m; scanf(lls,p+i));
	long long l=-1,r=max(h[n],p[m])<<1|1,ans=0;
	while(l+1<r){
		long long mid=l+r>>1;
		if(judge(mid))
			ans=mid,r=mid;
		else
			l=mid;
	}
	printf(lls "\n",ans);
	return 0;
}