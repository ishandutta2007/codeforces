//CF1129B
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
const int N = 2000;
const int B = 9e5;
int a[2222];
int main()
{
	int s,i,x,y,z;
	cin>>s;
	for(x=3;x<=N;x=x+1){
		y=s/(x-1)+2;
		z=x*y-s;
		if(x+y>z||z>B)
			continue;
		a[1]=z;
		a[2]=-z-3;
		for(i=3;i<x;i=i+1)
			a[i]=-1;
		a[x]=y+x;
		cout<<x<<endl;
		for(i=1;i<=x;i=i+1)	
			cout<<a[i]<<' ';
		return 0;
	}
	return 0;
}