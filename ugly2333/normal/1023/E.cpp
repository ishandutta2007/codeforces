//CF 1023E
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
char ch[11];
int q(int r1,int c1,int r2,int c2){
	cout<<"? "<<r1<<' '<<c1<<' '<<r2<<' '<<c2<<endl;
	cin>>ch;
	return ch[0]=='Y';
}
string s,t;
int main()
{
	int n,i,j,x,y;
	cin>>n;
	x=1,y=1;
	for(i=1;i<n;i=i+1){
		if(x<n&&q(x+1,y,n,n))
			x++,s+='D';
		else
			y++,s+='R';
	}
	x=n,y=n;
	for(i=1;i<n;i=i+1){
		if(y>1&&q(1,1,x,y-1))
			y--,t='R'+t;
		else
			x--,t='D'+t;
	}
	s+=t;
	cout<<"! "<<s<<endl;
	return 0;
}