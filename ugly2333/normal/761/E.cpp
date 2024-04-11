//CF 761E
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
typedef long long LL;
using namespace std;
const LL inf = (LL)1000000000*1000000000/4;
bool f;
vector<int> v[100];
pair<LL,LL> ans[100];
//d 0 1 2 3
//  L D R U
void solve(int u,int fa,int d,LL lx,LL rx,LL ly,LL ry)
{
	if(u<=0)
		return;
	//cout<<u<<' '<<d<<' '<<v[u].size()<<endl;
	if(v[u].size()>4||f==0){
		f=0;
		return;
	}
	int i,h[10],j,k;
	LL xx,yy,llx,rrx,lly,rry;
	xx=(lx+rx)/2;
	yy=(ly+ry)/2;
	llx=(lx+lx+rx)/3;
	rrx=(rx+rx+lx)/3;
	lly=(ly+ly+ry)/3;
	rry=(ry+ry+ly)/3;
	ans[u].first=xx;
	ans[u].second=yy;
	if(fa!=0){
		if(d==0||d==2)
			ans[u].second=ans[fa].second;
		else
			ans[u].first=ans[fa].first;
	}
	//cout<<ans[u].first<<' '<<ans[u].second<<endl;
	if(v[u].size()==1&&fa!=0)
		return;
	j=0;
	for(i=0;i<4;i=i+1){
		if(j>=v[u].size()||i==(d+2)%4){
			h[i]=0;
		}
		else{
			if(v[u][j]==fa){
				if(j<v[u].size()-1)
					h[i]=v[u][j+1];
				else
					h[i]=0;
				j=j+1;
			}
			else
				h[i]=v[u][j];
			j=j+1;
		}
		//cout<<h[i]<<' ';
	}
	//cout<<endl;
	if(fa==0){
		for(i=0;i<v[u].size();i=i+1)
			h[i]=v[u][i];
		for(i=v[u].size();i<4;i=i+1)
			h[i]=0;
	}
	if(f) solve(h[0],u,0,lx,llx,lly,rry);
	if(f) solve(h[1],u,1,llx,rrx,ly,lly);
	if(f) solve(h[2],u,2,rrx,rx,lly,rry);
	if(f) solve(h[3],u,3,llx,rrx,rry,ry);
	return;
}
int main()
{
	int n,i,a,b;
	cin>>n;
	for(i=1;i<n;i=i+1){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	f=1;
	solve(1,0,4,10,inf,10,inf);
	if(f==0){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	//cout<<((LL)10+inf)/2<<endl;
	for(i=1;i<=n;i=i+1)
		cout<<ans[i].first<<' '<<ans[i].second<<endl;
	return 0;
}
/*
8
7 8
8 2
2 4
8 6
8 5
7 3
7 1
*/