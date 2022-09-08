//CF1726A
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
int n,a[N],f[N];
char s[N];
vector<int> v;
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
int main()
{
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		v.clear();
		for(i=1;i<=n*2;i++){
			if(s[i]=='(')
				v.push_back(i);
			else{
				x=v.back();
				a[i]=x,a[x]=i;
				v.pop_back();
			}
			f[i]=i;
		}
		for(i=1;i<=n*2;i++)
			f[fnd(i)]=fnd(a[i]);
		for(i=1;i<n*2;i++)
			if(a[i]<i&&i+1<a[i+1])
				f[fnd(i)]=fnd(i+1);
		x=0;
		for(i=1;i<=n*2;i++)
			x+=f[i]==i;
		printf("%d\n",x);
	}
	return 0;
}