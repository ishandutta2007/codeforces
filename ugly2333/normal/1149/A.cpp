//CF1149A
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
int n,a,b;
int main()
{
	int i,j,x,s;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		if(x==1)
			a++;
		else
			b++;
	}
	if(a==0||b==0){
		for(i=1;i<=n;i=i+1)
			cout<<x<<' ';
		return 0;
	}
	a--;
	b--;
	cout<<"2 1";
	for(i=1;i<=b;i=i+1)
		cout<<" 2";
	for(i=1;i<=a;i=i+1)
		cout<<" 1";
	return 0;
}