//CF 900A
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
	int n,i,s1,s2,x,y;
	scanf("%d",&n);
	s1=0,s2=0;
	while(n--){
		scanf("%d%d",&x,&y);
		if(x>0)
			s1++;
		else
			s2++;
	}
	if(s1<2||s2<2)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}