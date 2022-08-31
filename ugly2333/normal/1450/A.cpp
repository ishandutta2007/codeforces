//CF1450A
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
char c[11111];
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,c);
		sort(c,c+n);
		cout<<c<<endl;
	}
	return 0;
}