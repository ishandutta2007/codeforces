//CF 845C
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
int b[222222],e[222222];
int main()
{
	int n,i,s,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",b+i,e+i);
		e[i]++;
	}
	sort(b+1,b+n+1);
	sort(e+1,e+n+1);
	b[n+1]=1<<30;
	e[n+1]=1<<30;
	x=1;
	y=1;
	s=0;
	for(i=1;i<=n+n;i=i+1){
		if(b[x]>=e[y]){
			s--;
			y++;
		}
		else{
			s++;
			x++;
		}
		if(s>2){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}