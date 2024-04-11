//CF1545A
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
int n,p,q,a[N],b[N];
int main()
{
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		p=0,q=0;
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			if(i&1)
				a[++p]=x;
			else
				b[++q]=x;
		}
		sort(a+1,a+p+1);
		sort(b+1,b+q+1);
		x=1;
		for(i=1;i<=q;i++)
			if(a[i]>b[i])
				x=0;
		for(i=2;i<=p;i++)
			if(b[i-1]>a[i])
				x=0;
		if(x)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}