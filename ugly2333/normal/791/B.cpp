//CF 791B
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
vector<int> v[150005];
int f[150005];
int main()
{
	int n,m,i,j,k,x,y,s,ss;
	cin>>n>>m;
	for(i=1;i<=m;i=i+1){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i=i+1){
		v[i].push_back(i);
		s=v[i].size();
		sort(v[i].begin(),v[i].end());
		if((long long)s*(s-1)>(long long)2*m+1){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(i=1;i<=n;i=i+1)
	{
		if(f[i]==1)
			continue;
		s=v[i].size();
		for(j=0;j<s;j=j+1){
			f[v[i][j]]=1;
			if(v[v[i][j]].size()!=s){
				cout<<"NO"<<endl;
				return 0;
			}
		}
		for(j=0;j<=s-2;j=j+1)
			for(k=0;k<s;k=k+1)
				if(v[v[i][j]][k]!=v[v[i][j+1]][k]){
					cout<<"NO"<<endl;
					return 0;
				}
	}
	cout<<"YES"<<endl;
	return 0;
}