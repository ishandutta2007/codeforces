
#include<bits/stdc++.h>
using namespace std;
#define For(i,x,y) for(int i = (int)(x);i <= (int)(y);++i)
map<long long,long long>mp;
int n,a[10001000],k;
int main(){
	long long T;
	scanf("%lld",&T);
	for(;T--;mp.clear()){
		scanf("%d%d",&n,&k);	
		int sum=0;
		For(i,1,n)scanf("%d",&a[i]),sum|=mp[a[i]-k]|mp[a[i]+k],mp[a[i]]=1;
		if (!sum)puts("NO");
		else	puts("YES");
	}
}