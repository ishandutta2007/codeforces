//CF1097C
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
const int N = 555555;
int n,l,a[N],b[N];
char c[N];
int main()
{
	int i,j,o,e;
	scanf("%d",&n);
	for(j=1;j<=n;j=j+1){
		scanf("%s",c+1);
		l=strlen(c+1);
		o=0,e=1;
		for(i=1;i<=l;i=i+1){
			if(c[i]=='(')
				o++;
			else
				o--;
			if(o<0)
				e=0;
		}
		if(e)
			a[o]++;
		if(e&&!o)
			continue;
		o=0,e=1;
		for(i=l;i;i=i-1){
			if(c[i]==')')
				o++;
			else
				o--;
			if(o<0)
				e=0;
		}
		if(e)
			b[o]++;
	}
	o=a[0]/2;
	for(i=1;i<N;i=i+1)
		o+=min(a[i],b[i]);
	cout<<o;
	return 0;
}