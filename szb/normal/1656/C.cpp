
#include<bits/stdc++.h>
using namespace std;
#define For(i,x,y) for(int i = (int)(x);i <= (int)(y);++i)
map<long long,long long>mp;
int n,a[10001000];
int main(){
	long long T;
	scanf("%lld",&T);
	for(;T--;mp.clear()){
		scanf("%d",&n);	
		int sum=0;
		For(i,1,n)scanf("%d",&a[i]),sum|=a[i]==1,mp[a[i]]=1;
		if (!sum)puts("YES");
		else{
			int fl=1;
			For(i,1,n)
				if (mp[a[i]+1])fl=0;
			if (fl)	puts("YES");
			else 	puts("NO");
		}
	}
}