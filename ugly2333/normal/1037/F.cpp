//CF 1037F
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
const int N = 1111111;
const int MO = 1e9+7;
int n,k,a[N],l[N],r[N];
vector<pair<int,int> > v;
LL ans,s;
int main()
{
	int i,x,y;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i),ans-=a[i];
	v.clear();
	v.push_back(make_pair(MO,0));
	for(i=1;i<=n;i=i+1){
		while(*v.rbegin()<make_pair(a[i],i)){
			v.pop_back();
		}
		l[i]=i-(*v.rbegin()).second;
		v.push_back(make_pair(a[i],i));
	}
	v.clear();
	v.push_back(make_pair(MO,n+1));
	for(i=n;i;i=i-1){
		while(*v.rbegin()<make_pair(a[i],i)){
			v.pop_back();
		}
		r[i]=(*v.rbegin()).second-i;
		v.push_back(make_pair(a[i],i));
	}
	k--;
	for(i=1;i<=n;i=i+1){
		x=l[i]/k;
		s=(LL)x*r[i]%MO;
		x=l[i]%k;
		y=r[i]/k;
		s+=(LL)x*y%MO;
		y=r[i]%k;
		if(x&&y){
			if(x+y<=k+1)
				s++;
			else
				s+=x+y-k;
		}
		//cout<<i<<l[i]<<r[i]<<s<<endl;
		ans+=s*a[i]%MO;
	}
	s=(ans%MO+MO)%MO;
	cout<<s;
	return 0;
}