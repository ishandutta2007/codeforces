//CF 167E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 666;
int n,m,p,k;
vector<int> v[N],a,b;
int f[N],g[N];
queue<int> Q;
int r[N],dp[N];
int t[N][N];
int fpow(int x,int y=p-2){
	if(!y)
		return 1;
	LL z=fpow(x,y>>1);
	z=z*z%p;
	if(y&1)
		z=z*x%p;
	return z;
}
int main()
{
	int i,j,l,x,y,ans;
	scanf("%d%d%d",&n,&m,&p);
	while(m--){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		f[x]++,g[y]++;
	}
	for(i=1;i<=n;i=i+1){
		if(!f[i])
			b.push_back(i);
		if(!g[i])
			a.push_back(i);
	}
	k=a.size();
	for(i=0;i<k;i=i+1)
		Q.push(a[i]);
	i=0;
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		r[++i]=x;
		l=v[x].size();
		for(j=0;j<l;j=j+1){
			y=v[x][j];
			g[y]--;
			if(!g[y])
				Q.push(y);
		}
	}
	for(i=0;i<k;i=i+1){
		memset(dp,0,sizeof(dp));
		dp[a[i]]=1;
		for(j=1;j<=n;j=j+1){
			x=r[j];
			l=v[x].size();
			while(l--){
				y=v[x][l];
				dp[y]=(dp[y]+dp[x])%p;
			}
		}
		for(j=0;j<k;j=j+1)
			t[i][j]=dp[b[j]];
	}
	ans=1;
	for(i=0;i<k;i=i+1){
		for(j=i;j<k;j=j+1)
			if(t[j][i])
				break;
		if(j>=k){
			cout<<0<<endl;
			return 0;
		}
		if(i<j){
			for(l=0;l<k;l=l+1)
				swap(t[i][l],t[j][l]);
			ans=p-ans;
		}
		ans=(LL)ans*t[i][i]%p;
		for(j=i+1;j<k;j=j+1){
			if(!t[j][i])
				continue;
			x=(LL)t[i][i]*fpow(t[j][i])%p;
			for(l=0;l<k;l=l+1)
				t[j][l]=(LL)t[j][l]*x%p;
			ans=(LL)ans*fpow(x)%p;
			for(l=0;l<k;l=l+1)
				t[j][l]=(t[j][l]-t[i][l]+p)%p;
		}
	}
	cout<<ans<<endl;
	return 0;
}