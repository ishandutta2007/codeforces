#include<bits/stdc++.h>
using namespace std;
int n,m,r,k,at[100005];
int sa[100005],sb[100005];
long long ans;
priority_queue<pair<long long,int> > q;
int cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&r,&k);
	for (int i=1;i+r-1<=n;i++)
		sa[i]++,sa[i+r]--;
	for (int i=1;i+r-1<=m;i++)
		sb[i]++,sb[i+r]--;
	for (int i=1;i<=n;i++)
		sa[i]+=sa[i-1];
	for (int i=1;i<=m;i++)
		sb[i]+=sb[i-1];
	sort(sb+1,sb+m+1,cmp);
	for (int i=1;i<=n;i++){
		q.push(make_pair(1ll*sa[i]*sb[1],i));
		at[i]=1;
	}
	for (int i=1;i<=k;i++){
		ans+=q.top().first;
		//printf("%I64d\n",q.top().first);
		int tmp=q.top().second;
		q.pop();
		q.push(make_pair(1ll*sa[tmp]*sb[++at[tmp]],tmp));
	}
	printf("%.15lf\n",1.0*ans/(n-r+1)/(m-r+1));
}