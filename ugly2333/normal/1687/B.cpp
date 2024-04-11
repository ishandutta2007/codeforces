//CF1687B
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
const int N = 555;
int n,m,a[N];
pair<int,int> p[N];
string s;
int main()
{
	int i,x,y,z;
	cin>>n>>m;
	for(i=0;i<m;i++)
		s+="0";
	for(i=0;i<m;i++){
		s[i]='1';
		cout<<"? "<<s<<endl;
		cin>>a[i];
		p[i]=make_pair(a[i],i);
		s[i]='0';
	}
	sort(p,p+m);
	x=0;
	z=0;
	for(i=0;i<m;i++){
		s[p[i].second]='1';
		cout<<"? "<<s<<endl;
		cin>>y;
		if(y==x+p[i].first)
			z+=p[i].first;
		x=y;
	}
	cout<<"! "<<z<<endl;
	return 0;
}