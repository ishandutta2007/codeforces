//CF612F
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
const int N = 2222;
const int inf = 1e9;
int n,s,m,a[N],b[N],c[N],f[N],g[N],h[N],p[N];
vector<int> v[N],ans2;
vector<pair<int,int> > ans;
map<int,int> M;
map<int,int>::iterator it;
void F(int i,int w,int P,int G,int H=0){
	if(f[i]>w)
		f[i]=w,g[i]=G,h[i]=H,p[i]=P;
}
void go(int x,int y,int s,int w){
	int o,a,b;
	if(x<y)
		o=x<s&&s<y;
	else
		o=x<s||s<y;
	if(o){
		a=(x-s+n)%n;
		F(x,w+a,s,a);
		a=(s-y+n)%n;
		F(y,w+a,s,-a);
		return;
	}
	b=(x-y+n)%n;
	a=(s-y+n)%n;
	F(x,w+a+b,s,-a,b);
	a=(x-s+n)%n;
	F(y,w+a+b,s,a,-b);
}
void solve(vector<int>&v,int s,int w){
	int i,o=v.size(),a;
	if(o==1){
		o=v[0];
		a=(s-o+n)%n;
		F(o,w+a,s,-a);
		a=(o-s+n)%n;
		F(o,w+a,s,a);
		return;
	}
	for(i=1;i<o;i=i+1)
		go(v[i-1],v[i],s,w);
	go(v[o-1],v[0],s,w);
}
void q(int x,int o){
	int i;
	if(x>0){
		i=0;
		while(1){
			if(a[s]==o){
				ans2.push_back(i);
				i=0;
				a[s]=0;
			}
			if(!x)
				return;
			s=c[s];
			i++;
			x--;
		}
	}
	else{
		i=0;
		while(1){
			if(a[s]==o){
				ans2.push_back(i);
				i=0;
				a[s]=0;
			}
			if(!x)
				return;
			s=b[s];
			i--;
			x++;
		}
	}
}
int main()
{
	int i,j,x,o;
	cin>>n>>s;
	for(i=1;i<=n;i=i+1){
		cin>>a[i];
		M[a[i]]=1;
		b[i]=i-1;
		c[i]=i+1;
	}
	b[1]=n,c[n]=1;
	for(it=M.begin();it!=M.end();it++)
		(*it).second=++m;
	for(i=1;i<=n;i=i+1){
		a[i]=M[a[i]];
		v[a[i]].push_back(i);
	}
	solve(v[1],s,-inf);
	for(i=1;i<m;i=i+1){
		for(j=0;j<v[i].size();j=j+1){
			x=v[i][j];
			solve(v[i+1],x,f[x]);
		}
	}
	j=v[m][0];
	for(i=0;i<v[m].size();i=i+1){
		x=v[m][i];
		if(f[j]>f[x])
			j=x;
	}
	o=f[j]+inf;
	cout<<o<<endl;
	for(i=m;i;i=i-1){
		ans.push_back(make_pair(h[j],i));
		ans.push_back(make_pair(g[j],i));
		j=p[j];
	}
	for(i=ans.size();i--;)
		q(ans[i].first,ans[i].second);
	for(i=0;i<ans2.size();i=i+1){
		if(ans2[i]>=0)
			cout<<'+';
		cout<<ans2[i]<<endl;
	}
	return 0;
}