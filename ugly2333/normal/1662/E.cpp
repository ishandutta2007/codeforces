//CF1662E
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
int n,a[N],b[N],t[N];
void ad(int x,int y){
	while(x<=n){
		t[x]+=y;
		x+=x&-x;
	}
}
int qu(int x){
	int y=0;
	while(x){
		y+=t[x];
		x-=x&-x;
	}
	return y;
}
int cnt(int l,int r){
	if(l<r)
		return qu(r-1)-qu(l);
	return qu(r-1)+qu(n)-qu(l);
}
int main()
{
	int T,i;
	LL s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",a+i);
			b[a[i]]=i;
			ad(i,1);
		}
		s=0;
		for(i=1;i<n;i++){
			ad(b[i],-1);
			s+=(LL)i*cnt(b[i],b[i+1]);
		}
		for(i=1;i<=n;i++)
			t[i]=0;
		printf("%lld\n",s);
	}
	return 0;
}