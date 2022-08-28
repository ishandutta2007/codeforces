//
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
int n,a[N],b[N];
vector<int> v[N];
int main()
{
	int i,j,o,x;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		a[i]=n-a[i];
		v[a[i]].push_back(i);
	}
	x=1;
	for(i=1;i<=n;i=i+1){
		o=v[i].size();
		if(o%i){
			cout<<"Impossible";
			return 0;
		}
		for(j=0;j<o;j=j+1)
			b[v[i][j]]=x+j/i;
		x+=o/i;
	}
	cout<<"Possible\n";
	for(i=1;i<=n;i=i+1)
		cout<<b[i]<<' ';
	return 0;
}