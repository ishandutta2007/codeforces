//CF 911C
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
void yes(){
	cout<<"YES\n";
	exit(0);
}
void no(){
	cout<<"NO\n";
	exit(0);
}
int main()
{
	int x,y,z;
	cin>>x>>y>>z;
	if(x>y)
		swap(x,y);
	if(x>z)
		swap(x,z);
	if(y>z)
		swap(y,z);
	if(x==1)
		yes();
	if(x==2){
		if(y==2)
			yes();
		if(y==4&&z==4)
			yes();
		no();
	}
	if(z==3)
		yes();
	no();
	return 0;
}