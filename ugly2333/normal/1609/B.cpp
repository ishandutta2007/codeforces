//CF1609B
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
int n,q;
char s[N],t[11];
int ok(int i){
	return s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c';
}
int main()
{
	int i,o,x;
	scanf("%d%d",&n,&q);
	scanf("%s",s+2);
	o=0;
	for(i=0;i<=n;i++)
		o+=ok(i);
	while(q--){
		scanf("%d%s",&x,t);
		x++;
		o-=ok(x-2)+ok(x-1)+ok(x);
		s[x]=t[0];
		o+=ok(x-2)+ok(x-1)+ok(x);
		printf("%d\n",o);
	}
	return 0;
}