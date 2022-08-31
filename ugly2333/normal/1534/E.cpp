//CF1534E
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
const int N = 555;
int n,k,a[N];
pair<int,int> p[N];
vector<int> v[N];
void chk(int m){
	int i,j;
	for(j=1;j<=m;j++){
		for(i=1;i<=n;i++)
			p[i]=make_pair(a[i],i);
		sort(p+1,p+n+1);
		reverse(p+1,p+n+1);
		if(p[k].first<=0)
			return;
		v[j].clear();
		for(i=1;i<=k;i++)
			a[p[i].second]--,v[j].push_back(p[i].second);
	}
	int u=0,x;
	for(j=1;j<=m;j++){
		cout<<'?';
		for(i=0;i<k;i++)
			cout<<' '<<v[j][i];
		cout<<endl;
		cin>>x;
		u^=x;
	}
	cout<<'!'<<' '<<u<<endl;
	exit(0);
}
int main()
{
	int i,j,o,x;
	cin>>n>>k;
	if(k%2==0){
		if(n%2==1){
			cout<<-1;
			return 0;
		}
	}
	for(i=k;1;i+=k){
		if(i<n)
			continue;
		if((i-n)%2)
			continue;
		x=i;
		for(j=1;j<=n;j++)
			a[j]=1,x--;
		j=1;
		while(x){
			a[j]+=2;
			x-=2;
			j=j%n+1;
		}
		chk(i/k);
	}
	return 0;
}