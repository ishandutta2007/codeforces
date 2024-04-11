//CF 1034B
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
int main()
{
	LL n,m,s;
	cin>>n>>m;
	s=n*m;
	if(n>m)
		swap(n,m);
	if(n==1){
		if(s%6>=3)
			cout<<s-6+s%6;
		else
			cout<<s-s%6;
		return 0;
	}
	if(n==2){
		if(m==2)
			cout<<0;
		else{
			if(m==3||m==7)
				cout<<s-2;
			else
				cout<<s;
		}
		return 0;
	}
	if(n%2==0||m%2==0){
		cout<<s;
		return 0;
	}
	cout<<s-1;
	return 0;
}