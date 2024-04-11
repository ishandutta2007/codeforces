//CF 810A
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
int main()
{
	int n,k,i,s,x;
	cin>>n>>k;
	s=0;
	for(i=1;i<=n;i=i+1){
		cin>>x;
		s+=x;
	}
	x=0;
	while(s<k*n-n/2){
		s+=k;
		n++;
		x++;
	}
	cout<<x<<endl;
	return 0;
}