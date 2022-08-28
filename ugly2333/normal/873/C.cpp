//CF 873C
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
const int N = 111;
int a[N][N];
int n,m,k,ans,anss;
void solve(int j){
	int i,s,ss,mxs,mnss;
	s=0,ss=0,mxs=0,mnss=0;
	for(i=1;i<=n;i=i+1){
		s+=a[i][j];
		if(i>=k){
			s-=a[i-k][j];
			ss+=a[i-k][j];
			if(s>mxs)
				mxs=s,mnss=ss;
		}
	}
	ans+=mxs;
	anss+=mnss;
}
int main()
{
	int i,j;
	cin>>n>>m>>k;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
			cin>>a[i][j];
	for(i=1;i<=m;i=i+1)
		solve(i);
	cout<<ans<<' '<<anss<<endl;
	return 0;
}