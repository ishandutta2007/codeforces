//CF 899A
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
	int n,x,s1,s2;
	s1=0,s2=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		if(x==1)
			s1++;
		else
			s2++;
	}
	if(s2>=s1)
		x=s1;
	else
		x=s2+(s1-s2)/3;
	cout<<x<<endl;
	return 0;
}