//CF 837A
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
char c[111111];
int main()
{
	int n,s,i,l,x;
	cin>>n;
	s=0;
	while(cin>>c){
		l=strlen(c);
		x=0;
		for(i=0;i<l;i=i+1)
			if(c[i]>='A'&&c[i]<='Z')
				x++;
		s=max(s,x);
	}
	cout<<s<<endl;
	return 0;
}