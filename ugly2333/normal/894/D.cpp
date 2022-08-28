//CF 894D
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
const int N = 1e6+16;
const int M = 1e5+15;
const int Q = 21;
const int inf = 1e9;
int n,m,d[N],l[N],dep[N];
vector<pair<int,int> > v[N];
vector<int> c[N];
LL ans[M],s[N];
void mrg(int x){
	//cout<<x<<endl;
	int i,j,s0,s1,fl,t;
	s0=c[x<<1].size();
	s1=c[x<<1|1].size();
	//cout<<s0<<s1;
	i=0,j=0;
	fl=1;
	while(i<s0||j<s1||fl){
		t=inf;
		if(fl)
			t=dep[x];
		if(i<s0&&c[x<<1][i]<t)
			t=c[x<<1][i];
		if(j<s1&&c[x<<1|1][j]<t)
			t=c[x<<1|1][j],j++;
		else{
			if(fl&&t==dep[x])
				fl=0;
			else
				i++;
		}
		c[x].push_back(t);
		//cout<<t<<' ';
	}
	//cout<<endl;
	c[x<<1].clear();
	c[x<<1|1].clear();
}
int main()
{
	int i,j,k,x,y,z;
	scanf("%d%d",&n,&m);
	d[1]=0;
	dep[1]=0;
	for(i=2;i<=n;i=i+1){
		scanf("%d",l+i);
		d[i]=d[i>>1]+1;
		dep[i]=dep[i>>1]+l[i];
	}
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(make_pair(y,i));
		while(x>1){
			y-=l[x];
			x^=1;
			if(x<=n&&y>l[x])
				v[x].push_back(make_pair(y-l[x],i));
			x>>=1;
			if(y>0)
				ans[i]+=(LL)y;
			else
				break;
		}
	}
	for(i=d[n];i>=0;i=i-1){
		x=1<<i;
		y=min(x+x-1,n);
		for(j=x;j<=y;j=j+1){
			if(j+j<=n)
				mrg(j);
			else
				c[j].push_back(dep[j]);
			if(!v[j].size())
				continue;
			s[0]=c[j][0];
			for(k=1;k<c[j].size();k=k+1)
				s[k]=s[k-1]+c[j][k];
			for(k=0;k<v[j].size();k=k+1){
				z=upper_bound(c[j].begin(),c[j].end(),v[j][k].first+dep[j])-c[j].begin();
				//cout<<z<<j<<s[0]<<endl;
				ans[v[j][k].second]+=(LL)(v[j][k].first+dep[j])*z-s[z-1];
			}/**/
		}
	}
	for(i=1;i<=m;i=i+1)
		cout<<ans[i]<<endl;
	return 0;
}