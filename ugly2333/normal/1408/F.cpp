//CF1408F
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
const int N = 15555;
int n;
vector<int> v1,v2;
void go(int i,int j){
	v1.push_back(i);
	v2.push_back(j);
}
void solve(int l,int r){
	if(l==r)
		return;
	int h=l+r>>1,i,j;
	solve(l,h);
	solve(h+1,r);
	for(i=l,j=h+1;i<=h;i=i+1,j=j+1)
		go(i,j);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i+i<n;i*=2);
	solve(1,i),solve(n-i+1,n);
	printf("%d\n",v1.size());
	for(i=0;i<v1.size();i=i+1)
		printf("%d %d\n",v1[i],v2[i]);
	return 0;
}