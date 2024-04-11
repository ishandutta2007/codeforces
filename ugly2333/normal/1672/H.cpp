//CF1726H
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
int n,q,a[N],b[N];
char s[N];
int f(int x,int y){
	return x+y-min(x,y)+1;
}
int main()
{
	int i,l,r;
	scanf("%d%d%s",&n,&q,s+1);
	for(i=2;i<=n;i++){
		a[i]=a[i-1]+(s[i]==s[i-1]&&s[i]=='0');
		b[i]=b[i-1]+(s[i]==s[i-1]&&s[i]=='1');
	}
	while(q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",f(a[r]-a[l],b[r]-b[l]));
	}
	return 0;
}