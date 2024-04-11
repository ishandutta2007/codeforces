//CF 8E
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
int rev(int x,int n){
	int r=0;
	while(n--){
		r=r+r+(x&1);
		x>>=1;
	}
	return r;
}
void prt(int x,int n){
	while(n--){
		if(x&(1<<n))
			cout<<1;
		else
			cout<<0;
	}
}
int main()
{
	int n,t,m,i,j,l,r,f;
	LL k,o;
	cin>>n>>k;
	k++;
	t=n>>1;
	m=n-t-1;
	for(i=0;i<(1<<m);i=i+1){
		l=i>>(n&1);
		r=(1<<t)-1-l;
		if(n&i&1)
			r--;
		o=r-l+1;
		//cout<<l<<' '<<r<<' '<<o<<endl;
		if(k<=o){
			prt(i,m+1);
			for(i=0;i<(1<<t);i=i+1){
				j=rev(i,t);
				if(l<=j&&j<=r)
					k--;
				if(!k)
					break;
			}
			prt(i,t);
			return 0;
		}
		k-=o;
	}
	cout<<-1;
	return 0;
}