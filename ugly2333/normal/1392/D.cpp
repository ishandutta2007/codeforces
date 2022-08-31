//CF1392D
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
const int N = 222222;
char s[N];
int n;
vector<int> v;
int main()
{
	int T,i,x,l;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		x=1;
		for(i=1;i<=n;i=i+1)
			if(s[i]!=s[1])
				x=0;
		if(x){
			printf("%d\n",(n+2)/3);
			continue;
		}
		s[n+1]=0;
		x=1;
		for(i=2;i<=n+1;i=i+1){
			if(s[i]!=s[i-1])
				v.push_back(x),x=1;
			else
				x++;
		}
		l=v.size();
		if(s[1]==s[n])
			v[0]+=v[l-1],l--;
		x=0;
		for(i=0;i<l;i=i+1)
			x+=v[i]/3;
		v.clear();
		printf("%d\n",x);
	}
	return 0;
}