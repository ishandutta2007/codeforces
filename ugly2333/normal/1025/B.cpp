//CF 1025B
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
LL gcd(LL x,LL y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
int main()
{
	int n,i,x,y;
	LL s,p;
	s=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&x,&y);
		s=gcd(s,(LL)x*y);
	}
	for(i=2;i<=2e6;i=i+1){
		if(s%i==0){
			cout<<i;
			return 0;
		}
		while(x%i==0){
			x/=i;
		}
		while(y%i==0){
			y/=i;
		}
	}
	if(x>1&&s%x==0){
		cout<<x;
		return 0;
	}
	if(y>1&&s%y==0){
		cout<<y;
		return 0;
	}
	cout<<-1;
	return 0;
}