//CF1404A
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
const int N = 333333;
int n,k,a[N];
char s[N];
int main()
{
	int T,i,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%s",&n,&k,s);
		for(i=0;i<k;i=i+1)
			a[i]=0;
		for(i=0;i<n;i=i+1){
			if(s[i]=='0')
				a[i%k]|=1;
			if(s[i]=='1')
				a[i%k]|=2;
		}
		x=0;
		for(i=0;i<k;i=i+1)
			if(a[i]==3)
				x=1;
		if(x){
			cout<<"NO\n";
			continue;
		}
		x=0,y=0;
		for(i=0;i<k;i=i+1){
			if(a[i]==1)
				x++;
			if(a[i]==2)
				y++;
		}
		if(x<=k/2&&y<=k/2)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}