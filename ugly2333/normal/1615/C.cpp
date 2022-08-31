//CF1615A
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
const int N = 111111;
int n,s[2][2];
char a[N],b[N];
int main()
{
	int T,i,t;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s",&n,a,b);
		memset(s,0,sizeof(s));
		for(i=0;i<n;i++)
			s[a[i]-'0'][b[i]-'0']++;
		t=N;
		if(s[0][1]==s[1][0])
			t=min(t,s[0][1]+s[1][0]);
		if(s[1][1]-s[0][0]==1)
			t=min(t,s[0][0]+s[1][1]);
		if(t>n)
			t=-1;
		printf("%d\n",t);
	}
	return 0;
}