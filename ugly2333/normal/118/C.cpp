//CF 118C
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
int n,m,b[11];
string s,t,r;
int main()
{
	int i,j,k,x,y,z;
	cin>>n>>m>>s;
	for(i=0;i<n;i=i+1)
		s[i]-='0',b[s[i]]++;
	z=1e9;
	for(j=0;j<10;j=j+1){
		x=b[j];
		y=0;
		t=s;
		for(k=1;x<m&&k<10;k=k+1){
			for(i=0;x<m&&i<n;i=i+1)
				if(t[i]==j+k)
					t[i]=j,x++,y+=k;
			for(i=n-1;x<m&&i>=0;i=i-1)
				if(t[i]==j-k)
					t[i]=j,x++,y+=k;
		}
		if(y<z)
			z=y,r=t;
		else{
			if(y==z&&t<r)
				r=t;
		}
	}
	cout<<z<<endl;
	for(i=0;i<n;i=i+1)
		cout<<(char)(r[i]+'0');
	return 0;
}