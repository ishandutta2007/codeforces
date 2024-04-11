//CF115D
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
const int N = 2222;
const int MO = 1e6+3;
int n,f[N][N];
string s,t;
int main()
{
	int i,j;
	cin>>s;
	n=s.length();
	s='+'+s;
	for(i=1;i<=n;i=i+1){
		if(s[i]=='/')
			s[i]='*';
		if(s[i]=='-')
			s[i]='+';
		if(s[i]=='*'&&s[i-1]=='+'){
			cout<<0;
			return 0;
		}
		if(s[i]=='*')
			s[i]='+';
		if(s[i]=='+')
			t+='+';
		else{
			if(s[i-1]=='+')
				t+='0';
		}
	}
	s=t;
	n=s.length();
	s='+'+s;
	f[0][0]=1;
	for(i=1;i<=n;i=i+1){
		for(j=n;j>=0;j=j-1){
			if(s[i]=='+')
				if(j)
					f[i][j]=f[i-1][j-1];
			if(s[i]=='0')
				f[i][j]=f[i-1][j]+f[i][j+1];
			f[i][j]%=MO;
		}
	}
	cout<<f[n][0];
	return 0;
}