//CF1090K
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
const int B = 2333;
const int M1 = 1e9+9;
const int M2 = 1e9+21;
string s,t;
map<pair<LL,int>,int> M;
pair<LL,int> p;
vector<int> v[111111];
int m,a[33];
int main()
{
	int n,i,j,o;
	LL x,y,z;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>s>>t;
		for(j=0;j<26;j=j+1)
			a[j]=0;
		for(j=0;j<t.length();j=j+1)
			a[t[j]-'a']=1;
		x=0;
		for(j=0;j<26;j=j+1)
			if(a[j])
				x|=(1<<j);
		o=-1;
		for(j=0;j<s.length();j=j+1)
			if(!a[s[j]-'a'])
				o=j;
		y=0;
		for(j=0;j<=o;j=j+1)
			y=(y*B+s[j])%M1;
		z=0;
		for(j=0;j<=o;j=j+1)
			z=(z*B+s[j])%M2;
		p=make_pair(y<<32|z,x);
		if(M.find(p)==M.end())
			M[p]=++m;
		v[M[p]].push_back(i);
	}
	cout<<m<<endl;
	for(i=1;i<=m;i=i+1){
		cout<<v[i].size();
		for(j=v[i].size();j--;)
			cout<<' '<<v[i][j];
		cout<<endl;
	}
	return 0;
}