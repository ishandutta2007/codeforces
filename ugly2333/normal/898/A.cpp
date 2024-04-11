//CF 898A
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
	int n;
	cin>>n;
	if(n%10<=4)
		n-=n%10;
	else
		n+=10-n%10;
	cout<<n<<endl;
	return 0;
}