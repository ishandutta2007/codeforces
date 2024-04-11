//CF1190C
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
const int N = 111111;
int n,k,a[N];
char s[N];
void T(){
	cout<<"tokitsukaze";
	exit(0);
}
void Q(){
	cout<<"quailty";
	exit(0);
}
void O(){
	cout<<"once again";
	exit(0);
}
set<int> S0,S1;
set<int>::iterator it;
int main()
{
	int i,j,x,y;
	scanf("%d%d%s",&n,&k,s+1);
	for(i=1;i<=n;i=i+1)
		a[i]=s[i]-'0';
	x=0;
	for(i=1;a[i]==a[1]&&i<=n;i=i+1)
		x++;
	y=0;
	for(i=n;a[i]==a[n]&&i>=1;i=i-1)
		y++;
	if(x+k>=n||y+k>=n)
		T();
	if(a[1]==a[n]&&x+y+k>=n)
		T();
	for(i=1;i<=n;i=i+1){
		if(a[i])
			S1.insert(i);
		else
			S0.insert(i);
	}
	for(i=1,j=k;j<=n;i=i+1,j=j+1){
		if(i<=*S1.begin())
			x=*S1.upper_bound(j);
		else
			x=*S1.begin();
		if(*S1.rbegin()<=j)
			it=S1.lower_bound(i),it--,y=*it;
		else
			y=*S1.rbegin();
		if(y-x+1>k)
			O();
		if(i<=*S0.begin())
			x=*S0.upper_bound(j);
		else
			x=*S0.begin();
		if(*S0.rbegin()<=j)
			it=S0.lower_bound(i),it--,y=*it;
		else
			y=*S0.rbegin();
		if(y-x+1>k)
			O();
	}
	Q();
	return 0;
}