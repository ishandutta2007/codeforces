//CF 888B
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
	int n,u,d,l,r,i;
	char ch[111];
	scanf("%d%s",&n,&ch);
	u=0,d=0,l=0,r=0;
	for(i=0;i<n;i=i+1){
		if(ch[i]=='U')
			u++;
		if(ch[i]=='D')
			d++;
		if(ch[i]=='L')
			l++;
		if(ch[i]=='R')
			r++;
	}
	cout<<2*(min(u,d)+min(l,r))<<endl;
	return 0;
}