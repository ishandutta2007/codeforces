//CF 852G
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
const int N = 111111;
const int M = 5555;
const int mod1 = 1e9+37;
const int mod2 = 1e9+91;
char a[N][55],b[M][55];
pair<LL,LL> ha[N];
vector<pair<LL,LL> > v[M];
void dfs(int i,int j,LL x,LL y){
	if(!b[i][j]){
		v[i].push_back(make_pair(x%mod1,y%mod2));
		return;
	}
	if(b[i][j]!='?'){
		x=((LL)x*6+b[i][j]-'a'+1)%mod1;
		y=((LL)y*6+b[i][j]-'a'+1)%mod2;
		dfs(i,j+1,x,y);
		return;
	}
	dfs(i,j+1,x,y);
	int k;
	x=((LL)x*6)%mod1;
	y=((LL)y*6)%mod2;
	for(k=1;k<=5;k=k+1){
		dfs(i,j+1,x+k,y+k);
	}
}
int ans[M];
int main()
{
	int n,m,i,j,s,h;
	LL x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1){
		scanf("%s",a[i]);
		j=0;
		x=0;
		y=0;
		while(a[i][j]){
			x=((LL)x*6+a[i][j]-'a'+1)%mod1;
			y=((LL)y*6+a[i][j]-'a'+1)%mod2;
			j++;
		}
		ha[i]=make_pair(x,y);
	}
	for(i=1;i<=m;i=i+1){
		scanf("%s",b[i]);
		dfs(i,0,0,0);
	}
	sort(ha+1,ha+n+1);
	for(i=1;i<=m;i=i+1){
		s=v[i].size();
		sort(v[i].begin(),v[i].end());
		s=unique(v[i].begin(),v[i].end())-v[i].begin();
		ans[i]=0;
		for(j=0;j<s;j=j+1){
			h=upper_bound(ha+1,ha+n+1,v[i][j])-lower_bound(ha+1,ha+n+1,v[i][j]);
			ans[i]+=h;
		}
		cout<<ans[i]<<endl;
	}
	//for(i=1;i<=sz;i=i+1)
	//	cout<<hb[i].first<<endl;
	return 0;
}