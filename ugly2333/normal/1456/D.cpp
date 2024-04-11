//CF1456D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 5555;
const int inf = 2e9;
int ab(int x){
	if(x<0)
		return -x;
	return x;
}
int n,t[N],p[N],a[N],b[N],g[N];
vector<int> l[N],r[N];
bool f[N][N];
bool cmp(int i,int j){
	return p[i]<p[j];
}
int e[N];
void E(int L,int R){//cout<<L<<' '<<R<<endl;
	e[lower_bound(b+1,b+n+1,L)-b]++;
	e[upper_bound(b+1,b+n+1,R)-b]--;
}
int dv(int x){
	if(x>=0)
		return x/2;
	return (x-1)/2;
}
int main()
{
	int i,j,k,x,L,R,fl,mx;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",t+i,p+i);
		a[i]=i;
	}
	for(i=n;i>=1;i=i-1)
		t[i]-=t[i-1];
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i=i+1)
		b[i]=p[a[i]];
	g[0]=1,l[0].push_back(0),r[0].push_back(0);
	for(i=1;i<=n;i=i+1){//cout<<i-1<<endl;for(j=1;j<=n;j=j+1)cout<<f[i-1][j];cout<<endl;
		memset(e,0,sizeof(e));
		mx=-1;
		for(k=0;k<g[i-1];k=k+1){//cout<<l[i-1][k]<<' '<<r[i-1][k]<<endl;
			if(l[i-1][k]<=p[i]&&p[i]<=r[i-1][k]){
				E(max(p[i]-t[i],dv(l[i-1][k]-t[i]+p[i]+1)),min(p[i]+t[i],dv(r[i-1][k]+t[i]+p[i])));
				mx=max(mx,t[i]);
			}
			else{
				if(p[i]<l[i-1][k]){
					L=p[i],R=l[i-1][k];
					x=R-L;
					x=t[i]-x;
					if(x>=0){
						E(p[i]-x/2,min(p[i]+t[i],dv(r[i-1][k]+t[i]+p[i])));
						mx=max(mx,x);
					}
				}
				else{
					L=r[i-1][k],R=p[i];
					x=R-L;
					x=t[i]-x;
					if(x>=0){
						E(max(p[i]-t[i],dv(l[i-1][k]-t[i]+p[i]+1)),p[i]+x/2);
						mx=max(mx,x);
					}
				}
			}
		}
		if(mx>=0){
			g[i]++;
			l[i].push_back(p[i]-mx);
			r[i].push_back(p[i]+mx);
		}
		fl=0;
		for(j=1;j<=n;j=j+1){
			if(f[i-1][j]){
				if(j==i){
					g[i]++;
					l[i].push_back(p[i-1]-t[i]);
					r[i].push_back(p[i-1]+t[i]);
				}
				L=min(p[i-1],p[i]),R=max(p[i-1],p[i]);
				x=R-L;
				x=t[i]-x;
				if(x>=0){
					f[i][j]=1;
					E(L-x/2,R+x/2);
				}
				fl=1;
			}//cout<<f[i-1][j];
		}//cout<<endl;
		if(fl){
			L=min(p[i-1],p[i]),R=max(p[i-1],p[i]);
			x=R-L;
			x=t[i]-x;
			if(x>=0){
				g[i]++;
				l[i].push_back(p[i]-x);
				r[i].push_back(p[i]+x);
			}
		}
		for(j=1;j<=n;j=j+1)
			e[j]+=e[j-1];
		for(j=1;j<=n;j=j+1)
			if(e[j])
				f[i][a[j]]=1;
	}
	x=g[n];
	for(i=1;i<=n;i=i+1)
		x|=f[n][i];
	if(x)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}