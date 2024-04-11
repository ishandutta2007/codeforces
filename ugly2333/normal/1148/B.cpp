//CF1148B
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
const int N = 222222;
int n,m,k,ta,tb,a[N],b[N],s;
int main()
{
	int i,x;
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	if(k>=n||k>=m){
		cout<<-1;
		return 0;
	}
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		a[i]+=ta;
	}
	for(i=1;i<=m;i=i+1)
		scanf("%d",b+i);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	s=0;
	for(i=0;i<=k;i=i+1){
		x=lower_bound(b+1,b+m+1,a[i+1])-b+k-i;
		if(x>m){
			cout<<-1;
			return 0;
		}
		s=max(s,b[x]+tb);
	}
	cout<<s;
	return 0;
}