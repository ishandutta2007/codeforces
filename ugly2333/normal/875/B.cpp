//CF 875B
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
int n,T[666666],f[333333];
void add1(int x){
	while(x<=n){
		T[x]++;
		x+=(x&-x);
	}
}
int query(int x){
	int res;
	res=0;
	while(x){
		res+=T[x];
		x-=(x&-x);
	}
	return res;
}
int main()
{
	int i,x,p;
	scanf("%d",&n);
	p=n;
	cout<<"1 ";
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		f[x]=1;
		while(f[p]){
			p--;
		}
		add1(x);
		cout<<1+query(p)<<' ';
	}
	return 0;
}