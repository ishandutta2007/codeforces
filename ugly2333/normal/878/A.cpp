//CF 878A
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
const int N = 5e5+55;
int f,f0,f1;
int main()
{
	char ch[5];
	int n,i,j,x,y,z;
	scanf("%d",&n);
	f0=0;
	f1=1023;
	for(i=1;i<=n;i=i+1){
		scanf("%s%d",&ch,&x);
		if(ch[0]=='&'){
			f0&=x;
			f1&=x;
		}
		if(ch[0]=='|'){
			f0|=x;
			f1|=x;
		}
		if(ch[0]=='^'){
			f0^=x;
			f1^=x;
		}
	}
	x=1023,y=0,z=0;//& | ^
	for(j=0;j<=9;j=j+1){
		if(f0&(1<<j)){
			if(f1&(1<<j))
				y+=(1<<j);
			else
				z+=(1<<j);
		}
		else{
			if(f1&(1<<j))
				;
			else
				x-=(1<<j);
		}
	}
	cout<<3<<endl;
	cout<<"^ "<<z<<endl;
	cout<<"& "<<x<<endl;
	cout<<"| "<<y<<endl;
	return 0;
}