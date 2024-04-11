#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int K=0;
pair<long long,long long> gg[233333];
inline void init(){
	long long x;
	cin>>x;
	long long x6=x*6;
	for(long long m=1;m<=3000000;m++)
	{
		long long a=x6-m-m*m,b=m*m+m;
		if(a%b!=0) continue;
		long long ans=a/b+m;
		if(ans%3!=0) continue;
		long long n=ans/3;
		if(n<m) continue;
		gg[++K]=make_pair(n,m);
		if(n!=m) gg[++K]=make_pair(m,n);
	}
	sort(gg+1,gg+1+K);
	cout<<K<<"\n";
	for(int i=1;i<=K;i++) printf("%I64d %I64d\n",gg[i].first,gg[i].second);
}
int main(){
	init();
	return 0;
}