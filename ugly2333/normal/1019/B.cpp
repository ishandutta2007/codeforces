//CF 1019B
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
	int n,x,h,l,r,ah,bh,al,ar,bl,br;
	cin>>n;
	if(n%4==2){
		cout<<"! -1"<<endl;
		return 0;
	}
	n>>=1;
	l=1,r=n+1;
	x=qu(l),al=x,br=x;
	x=qu(r),ar=x,bl=x;
	if(al==ar){
		cout<<"! "<<1<<endl;
		return 0;
	}
	while(l<r){
		h=l+r>>1;
		ah=qu(h);
		bh=qu(n+h);
		if(ah==bh){
			cout<<"! "<<h<<endl;
			return 0;
		}
		if((ah<bh)^(al<bl))
			r=h,ar=ah,br=bh;
		else
			l=h,al=ah,bl=bh;
	}
	return 0;
}