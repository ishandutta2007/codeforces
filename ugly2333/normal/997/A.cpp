//CF 997A
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
int n,x,y;
char a[N];
int main()
{
	int i;
	LL s=0;
	scanf("%d%d%d",&n,&x,&y);
	scanf("%s",a+1);
	for(i=1;i<=n;i=i+1)
		if(a[i]=='0')
			if(i==1||a[i-1]=='1')
				s++;
	if(!s)
		cout<<0<<endl;
	else
		cout<<(s-1)*min(x,y)+y<<endl;
	return 0;
}