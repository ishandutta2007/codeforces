#include <bits/stdc++.h>
using namespace std;
string s;
main(){
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++)	if(s[i]=='a')	cnt++;
	printf("%d\n",min((int)s.size(),cnt*2-1));
}