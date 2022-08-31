//CF 794A
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
int main()
{
	int s,n,i,x,l,r;
	s=0;
	cin>>x>>l>>r;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>x;
		if(x>l&&x<r)
			s++;
	}
	cout<<s<<endl;
	return 0;
}