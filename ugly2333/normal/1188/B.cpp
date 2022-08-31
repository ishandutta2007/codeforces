//CF1188B
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
int n,p,k,a[N];
LL ans;
map<int,int> M,S;
map<int,int>::iterator it;
LL c2(int x){
	return (LL)x*(x-1)/2;
}
int main()
{
	int i,x,y;
	scanf("%d%d%d",&n,&p,&k);
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		M[x]++;
		y=(LL)x*x%p;
		y=(LL)y*y%p;
		y-=(LL)x*k%p;
		y=(y+p)%p;
		S[y]++;
	}
	for(it=S.begin();it!=S.end();it++)
		ans+=c2((*it).second);
	for(it=M.begin();it!=M.end();it++){
		x=(*it).first;
		if((LL)x*x%p*x%p*4%p!=k)
			ans-=c2((*it).second);
	}
	cout<<ans;
	return 0;
}