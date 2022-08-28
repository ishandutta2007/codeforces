//CF1672E
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
int qu(int x){
	cout<<"? "<<x<<endl;
	cin>>x;
	return x;
}
int main()
{
	int n,i,l,r,h,s;
	scanf("%d",&n);
	l=1,r=5e6;
	while(l<r){
		h=l+r>>1;
		if(qu(h)==1)
			r=h;
		else
			l=h+1;
	}
	s=l;
	for(i=1;i<=n;i++){
		h=qu(l/i);
		if(h)
			s=min(s,l/i*h);
	}
	cout<<"! "<<s<<endl;
	return 0;
}