//CF 899C
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
	cout<<(n%4==1||n%4==2)<<endl<<(n+1)/2;
	while(n>3){
		cout<<' '<<n<<' '<<n-3;
		n-=4;
	}
	if(n)
		cout<<' '<<1;
	if(n==3)
		cout<<' '<<2;
	cout<<endl;
	return 0;
}