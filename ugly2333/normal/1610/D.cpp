//CF1610D
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
const int MO = 1e9+7;
int mul(int x,int y){
	return (LL)x*y%MO;
}
int p2(int x){
	int o=1;
	while(x--){
		o=o*2%MO;
	}
	return o;
}
int c[111];
int main()
{
	int n,i,a,b,x,y,s;
	scanf("%d",&n);
	a=0,b=0;
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		if(x%2==1)
			a++;
		else{
			b++;
			y=0;
			while(x%2==0){
				x/=2;
				y++;
			}
			c[y]++;
		}
	}
	x=p2(a)-1;
	y=p2(b)-1;
	s=x+mul(x,y),s%=MO;
	for(i=1;i<=30;i++){
		b-=c[i];
		if(c[i]){
			s+=mul(p2(c[i]-1)-1,p2(b));
			s%=MO;
		}
	}
	printf("%d",s);
	return 0;
}