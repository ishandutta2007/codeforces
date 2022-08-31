// CF 802G
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
char s[6],c;
int main()
{
	int i;
	s[0]='h';
	s[1]='e';
	s[2]='i';
	s[3]='d';
	s[4]='i';
	i=0;
	while(cin>>c){
		if(c==s[i])
			i++;
		if(i==5){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}