//CF1450D
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
const int N = 333333;
int n,a[N],b[N];
vector<int> v[N];
int main()
{
	int T,i,j,l,r,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i=i+1){
			scanf("%d",a+i);
			v[a[i]].push_back(i);
		}
		l=1,r=n;
		for(i=1;i<=n;i=i+1){
			if(!v[i].size())
				break;
			b[i]=1;
			if(v[i].size()>1||(v[i][0]!=l&&v[i][0]!=r))
				break;
			if(v[i][0]==l)
				l++;
			else
				r--;
		}
		x=1;
		for(i=1;i<=n;i=i+1)
			if(v[i].size()!=1)
				x=0;
		if(x)
			b[n]=1;
		for(i=n;i>=1;i=i-1)
			cout<<b[i];
		cout<<endl;
		for(i=1;i<=n;i=i+1)
			a[i]=0,b[i]=0,v[i].clear();
	}
	return 0;
}