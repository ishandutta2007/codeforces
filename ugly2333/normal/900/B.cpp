//CF 900B
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
	int a,b,c,i;
	cin>>a>>b>>c;
	for(i=1;i<=111111;i=i+1){
		a*=10;
		if(a/b==c){
			cout<<i<<endl;
			return 0;
		}
		a%=b;
	}
	cout<<-1<<endl;
	return 0;
}