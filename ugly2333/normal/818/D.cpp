// CF 818D
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
vector<int> v[1111111];
int s[111111];
int main()
{
	int n,k,i,x,z,j,f;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		s[i]=s[i-1];
		if(x==k)
			s[i]++;
		else
			v[x].push_back(i);
	}
	for(i=1;i<=1000005;i=i+1){
		if(i==k)
			continue;
		z=v[i].size();
		if(z<s[n])
			continue;
		f=1;
		for(j=0;j<z;j=j+1)
			if(s[v[i][j]]>j){
				f=0;
				break;
			}
		if(f){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}