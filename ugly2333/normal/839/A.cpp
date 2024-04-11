//CF 839A
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
int main()
{
	int n,k,i,x,y,s;
	cin>>n>>k;
	s=0;
	y=0;
	for(i=1;i<=n;i=i+1){
		cin>>x;
		s+=x;
		y+=min(8,s);
		s-=min(8,s);
		if(y>=k){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}