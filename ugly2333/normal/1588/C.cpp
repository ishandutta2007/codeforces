//CF1588C
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
int n,a[N];
LL s;
vector<LL> v0,v1;
LL l,r,k,b;
void ini(int x){
	l=0,r=x,k=-1,b=x;
}
void ins(int x){
	b+=x*k;
	k=-k;
	l=x-l,r=x-r;
	swap(l,r);
	if(l<0)
		l=0;
}
void gt(vector<LL>&v){
	if(l<=0&&0<=r)
		v.push_back(b);
}
void solve(int l,int r){
	if(l==r){
		s+=a[l]==0;
		return;
	}
	int h=l+r>>1,i,j,x,y;
	solve(l,h);
	solve(h+1,r);
	v0.clear();
	ini(a[h]);
	gt(v0);
	for(i=h-1;i>=l;i--)
		ins(a[i]),gt(v0);
	v1.clear();
	ini(a[h+1]);
	gt(v1);
	for(i=h+2;i<=r;i++)
		ins(a[i]),gt(v1);
	sort(v0.begin(),v0.end());
	sort(v1.begin(),v1.end());
	for(i=0,j=0;i<v0.size()&&j<v1.size();){
		if(v0[i]<v1[j]){
			i++;
			continue;
		}
		if(v0[i]>v1[j]){
			j++;
			continue;
		}
		x=1,y=1;
		while(i+1<v0.size()&&v0[i]==v0[i+1]){
			i++;
			x++;
		}
		while(j+1<v1.size()&&v1[j]==v1[j+1]){
			j++;
			y++;
		}
		s+=(LL)x*y;
		i++;
		j++;
	}
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		s=0;
		solve(1,n);
		printf("%lld\n",s);
	}
	return 0;
}