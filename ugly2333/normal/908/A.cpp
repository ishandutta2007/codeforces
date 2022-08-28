//CF 908A
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
	int n,i,s=0;
	char ch[55],c;
	cin>>ch;
	n=strlen(ch);
	for(i=0;i<n;i=i+1){
		c=ch[i];
		if(48<=c&&c<=57){
			if(c%2==1)
				s++;
		}
		else{
			if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
				s++;
		}
	}
	cout<<s;
	return 0;
}