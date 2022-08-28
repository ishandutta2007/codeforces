//CF1621G
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
const int N = 1<<18;
const int MO = 1e9+7;
int mul(int x,int y){
	return (LL)x*y%MO;
}
void ad(int &x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int n,m,a[N],f[N],g[N],h[N];
map<int,int> mp;
map<int,int>::iterator it;
int t[N];
void AD(int x,int y){
	while(x<=m){
		ad(t[x],y);
		x+=x&-x;
	}
}
int QU(int x){
	int y=0;
	while(x){
		ad(y,t[x]);
		x-=x&-x;
	}
	return y;
}
pair<int,int> p[N];
vector<int> v;
int main()
{
	int T,i,j,k,x,s,mx;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		mp.clear();
		for(i=1;i<=n;i++)
			scanf("%d",a+i),mp[a[i]]=1,p[i]=make_pair(a[i],-i);
		m=0;
		for(it=mp.begin();it!=mp.end();it++)
			(*it).second=++m;
		for(i=1;i<=n;i++)
			a[i]=mp[a[i]];
		memset(t,0,sizeof(t));
		for(i=1;i<=n;i++){
			f[i]=QU(a[i]-1);
			ad(f[i],1);
			AD(a[i],f[i]);//cout<<f[i]<<' ';
		}
		memset(t,0,sizeof(t));
		for(i=n;i>=1;i--){
			g[i]=QU(m);
			ad(g[i],MO-QU(a[i]));
			ad(g[i],1);
			AD(a[i],g[i]);//cout<<g[i]<<' ';
		}
		sort(p+1,p+n+1);
		j=1;
		mx=0;
		s=0;
		memset(t,0,sizeof(t));
		for(i=n;i>=1;i--){//cout<<i<<j<<endl;
			if(a[i]<mx){
				ad(s,mul(f[i],g[i]-h[i]+MO));
				continue;
			}
			mx=a[i];//cout<<i<<j<<x<<endl;
			v.clear();
			while(-p[j].second!=i){
				v.push_back(-p[j].second);
				j++;
			}
			j++;
			AD(a[i],1);
			sort(v.begin(),v.end());
			for(k=v.size()-1;k>=0;k--){
				x=v[k];//cout<<x<<endl;
				h[x]=QU(m);
				ad(h[x],MO-QU(a[x]));
				AD(a[x],h[x]);
			}
			/*AD(a[i],MO-1);
			for(k=0;k<v.size();k++)
				AD(a[v[k]],MO-h[v[k]]);*/
		}
		printf("%d\n",s);
	}
	return 0;
}