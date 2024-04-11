//CF1588B
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
LL query(int l,int r){
	LL x;
	cout<<'?'<<' '<<l<<' '<<r<<endl;
	cin>>x;
	return x;
}
int main()
{
	int T,n,l,r,h,i,j,k;
	LL x;
	cin>>T;
	while(T--){
		cin>>n;
		x=query(1,n);
		l=1,r=n;
		while(l<r){
			h=l+r>>1;
			if(query(1,h)==x)
				r=h;
			else
				l=h+1;
		}
		k=l;
		j=k-(query(1,k)-query(1,k-1));
		i=j-1-(query(1,j-1)-query(1,j-2));
		cout<<'!'<<' '<<i<<' '<<j<<' '<<k<<endl;
	}
	return 0;
}