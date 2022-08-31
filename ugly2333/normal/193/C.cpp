//CF 193C
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
typedef double DB;
string s[4];
int a[111];
int chk(int x){
	if(x%2){
		cout<<-1;
		exit(0);
	}
	return x/2;
}
int main()
{
	int i,j;
	cin>>a[12]>>a[13]>>a[14]>>a[23]>>a[24]>>a[34];
	a[1]=chk(a[24]+a[34]-a[12]-a[13]);
	a[2]=chk(a[23]+a[34]-a[12]-a[14]);
	a[3]=chk(a[13]+a[14]-a[34]);
	a[4]=chk(a[23]+a[24]-a[13]-a[14]);
	a[5]=chk(a[12]+a[14]-a[24]);
	a[6]=chk(a[12]+a[13]-a[23]);
	i=min(min(a[1],a[2]),min(a[4],a[7]));
	a[1]-=i,a[2]-=i,a[4]-=i,a[7]-=i;
	a[3]+=i,a[5]+=i,a[6]+=i;
	for(i=1;i<=7;i=i+1){
		if(a[i]<0){
			cout<<-1;
			return 0;
		}
		while(a[i]--){
			for(j=0;j<4;j=j+1){
				if(i&(1<<j))
					s[j]+='b';
				else
					s[j]+='a';
			}
		}
	}
	cout<<s[0].length()<<endl;
	for(j=0;j<4;j=j+1)
		cout<<s[3-j]<<endl;
	return 0;
}