//CF1103B
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
string s;
void rd(){
	cin>>s;
	if(s!="start")
		exit(0);
}
int q(int x,int y){
	cout<<"? "<<x<<' '<<y<<endl;
	cin>>s;
	if(s[0]=='x')
		return 1;
	if(s[0]=='y')
		return 0;
	exit(0);
}
int main()
{
	int i,l,r;
	while(1){
		rd();
		if(q(0,1)){
			cout<<"! "<<1<<endl;
			continue;
		}
		for(i=1;1;i<<=1)
			if(q(i,i+i))
				break;
		for(l=i+1,r=i+i;l<r;){
			i=((LL)l+r)/2;
			if(q(i,r))
				l=i+1;
			else
				r=i;
		}
		cout<<"! "<<l<<endl;
	}
	return 0;
}