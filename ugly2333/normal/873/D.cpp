//CF 873D
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
int n,k;
int ans[N];
void solve(int l,int r){// [l,r)
	if(l+1==r||!k){
		sort(ans+l,ans+r);
		return;
	}
	int md;
	md=(l+r)/2;
	k-=2;
	solve(l,md);
	solve(md,r);
}
int main()
{
	cin>>n>>k;
	if(k%2==0||k>2*n){
		cout<<-1<<endl;
		return 0;
	}
	int i;
	for(i=0;i<n;i=i+1)
		ans[i]=n-i;
	k--;
	solve(0,n);
	for(i=0;i<n;i=i+1)
		cout<<ans[i]<<' ';
	return 0;
}