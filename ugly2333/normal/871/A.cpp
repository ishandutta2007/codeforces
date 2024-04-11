//CF 871A
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
	int q,n,i;
	cin>>q;
	while(q--){
		cin>>n;
		if(n%4==0)
			cout<<n/4<<endl;
		if(n%4==1){
			if(n>=9)
				cout<<(n-9)/4+1<<endl;
			else
				cout<<-1<<endl;
		}
		if(n%4==2){
			if(n>=6)
				cout<<(n-6)/4+1<<endl;
			else
				cout<<-1<<endl;
		}
		if(n%4==3){
			if(n>=15)
				cout<<(n-15)/4+2<<endl;
			else
				cout<<-1<<endl;
		}
	}
	return 0;
}