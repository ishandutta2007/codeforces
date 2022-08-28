//CF1090D
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
const int N = 111111;
int n,m,a[N];
vector<int> v[N];
int main()
{
	int i,x,y;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	y=0;
	for(i=1;i<=n;i=i+1){
		a[i]=1;
		for(x=v[i].size();x--;)
			a[v[i][x]]=1;
		for(x=1;x<=n;x=x+1)
			if(!a[x])
				break;
		if(x<=n){
			y=i;
			break;
		}
		for(x=1;x<=n;x=x+1)
			a[x]=0;
	}
	if(!y){
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	for(i=1;i<=n;i=i+1)
		a[i]=0;
	a[x]=1,a[y]=2;
	x=2;
	for(i=1;i<=n;i=i+1)
		if(!a[i])
			a[i]=++x;
	for(i=1;i<=n;i=i+1)
		cout<<a[i]<<' ';
	cout<<endl;
	a[y]=1;
	for(i=1;i<=n;i=i+1)
		cout<<a[i]<<' ';
	return 0;
}