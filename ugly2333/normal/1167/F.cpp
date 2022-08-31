//CF 1167F
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
const int N = 555555;
const int MO = 1e9+7;
int n,a[N];
LL ans,t[N];
map<int,int> M;
map<int,int>::iterator it;
void ad(int x,int y){
	while(x<=n){
		t[x]+=y;
		x+=x&-x;
	}
}
int qu(int x){
	LL y=0;
	while(x){
		y+=t[x];
		x-=x&-x;
	}
	return y%MO;
}
int main()
{
	int i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		M[a[i]]=1;
	}
	x=0;
	for(it=M.begin();it!=M.end();it++)
		(*it).second=++x;
	memset(t,0,sizeof(t));
	for(i=1;i<=n;i=i+1){
		x=M[a[i]];
		ans+=(LL)(n-i+1)*qu(x)%MO*a[i]%MO;
		ad(x,i);
	}
	memset(t,0,sizeof(t));
	for(i=n;i;i=i-1){
		x=M[a[i]];
		ad(x,n-i+1);
		ans+=(LL)(i)*qu(x)%MO*a[i]%MO;
	}
	cout<<ans%MO;
	return 0;
}