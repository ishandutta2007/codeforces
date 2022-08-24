#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
char ch[110000];
int n;
int pd[300];
int main(){
	scanf("%s",ch+1); n=strlen(ch+1);
	pd['i']=1; pd['o']=1; pd['a']=1; pd['u']=1; pd['e']=1;
	for (int i='1';i<='9';i+=2) pd[i]=1;
	int ans=0;
	for (int i=1;i<=n;i++)
		ans+=pd[ch[i]];
	cout<<ans<<endl;
}