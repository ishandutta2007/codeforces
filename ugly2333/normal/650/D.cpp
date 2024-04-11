//CF 650D
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
const int N = 444444;
int n,a[N],m,b[N];
int q,qx[N],qy[N],ans[N];
pair<int,int> qq[N];
map<int,int> M;
map<int,int>::iterator it;
int T[N<<2][2];
void modify(int p,int w,int i,int k=1,int l=1,int r=m){
	if(l==r){
		T[k][i]=w;
		return;
	}
	int h=l+r>>1;
	if(p<=h)
		modify(p,w,i,k<<1,l,h);
	else
		modify(p,w,i,k<<1|1,h+1,r);
	T[k][i]=max(T[k<<1][i],T[k<<1|1][i]);
}
int query(int L,int R,int i,int k=1,int l=1,int r=m){
	if(L<=l&&r<=R)
		return T[k][i];
	if(r<L||R<L||R<l)
		return 0;
	int h=l+r>>1;
	return max(query(L,R,i,k<<1,l,h),query(L,R,i,k<<1|1,h+1,r));
}
int dp[N],f[N],g[N],pr[N];
vector<int> v[N];
int main()
{
	int i,j,e,x,y,xx,yy,s,w;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		M[a[i]]=1;
	}
	for(it=M.begin();it!=M.end();it++)
		M[(*it).first]=++m,b[m]=(*it).first;
	for(i=1;i<=q;i=i+1){
		scanf("%d%d",qx+i,qy+i);
		qq[i]=make_pair(qx[i],i);
	}
	memset(T,0,sizeof(T));
	e=0;
	for(i=1;i<=n;i=i+1){
		a[i]=M[a[i]];
		dp[i]=query(1,a[i]-1,0)+1;
		pr[i]=query(a[i],a[i],0);
		modify(a[i],dp[i],0);
		v[dp[i]].push_back(i);
		e=max(e,dp[i]);
	}
	s=v[e].size();
	for(i=0;i<s;i=i+1)
		f[v[e][i]]=1;
	if(s==1)
		g[v[e][0]]=1;
	for(i=e-1;i;i=i-1){
		j=i+1,s=0;
		x=v[i].size()-1,y=v[j].size()-1;
		while(x>=0&&y>=0){
			xx=v[i][x],yy=v[j][y];
			if(!f[yy]){
				y--;
				continue;
			}
			if(xx>yy){
				x--;
				continue;
			}
			if(a[xx]<a[yy])
				f[xx]=1,x--,s++,w=xx;
			else
				y--;
		}
		if(s==1)
			g[w]=1;
	}
	sort(qq+1,qq+q+1);
	j=q;
	for(i=n;i>=1;i=i-1){
		modify(a[i],pr[i],0);
		while(qq[j].first==i){
			x=qq[j].second;
			//y=M[qy[x]];
			y=lower_bound(b+1,b+m+1,qy[x])-b;
			xx=query(1,y-1,0);
			y=upper_bound(b+1,b+m+1,qy[x])-b;
			yy=query(y,m,1);
			s=xx+1+yy;
			if(s>=e)
				ans[x]=s;
			else{
				if(g[i])
					ans[x]=e-1;
				else
					ans[x]=e;
			}
			j--;
		}
		s=query(a[i]+1,m,1)+1;
		modify(a[i],s,1);
	}
	for(i=1;i<=q;i=i+1)
		cout<<ans[i]<<endl;
	return 0;
}