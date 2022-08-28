//CF1098A
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
const int inf = 2e9;
int n,f[N],s[N],p[N],a[N],b[N];
int main()
{
	int i;
	LL o=0;
	scanf("%d",&n);
	for(i=2;i<=n;i=i+1)
		scanf("%d",f+i);
	for(i=1;i<=n;i=i+1){
		scanf("%d",s+i);
		if(s[i]==-1)
			p[i]=inf;
		else
			p[i]=s[i];
	}
	for(i=n;i>1;i=i-1)
		p[f[i]]=min(p[f[i]],p[i]);
	a[1]=s[1],b[1]=a[1];
	for(i=2;i<=n;i=i+1){
		if(s[i]==-1){
			if(p[i]==inf){
				a[i]=0;
				continue;
			}
			if(b[f[i]]>p[i]){
				cout<<-1;
				return 0;
			}
			a[i]=p[i]-b[f[i]];
			b[i]=p[i];
		}
		else{
			if(b[f[i]]>s[i]){
				cout<<-1;
				return 0;
			}
			a[i]=s[i]-b[f[i]];
			b[i]=s[i];
		}
	}
	for(i=1;i<=n;i=i+1)
		o+=a[i];
	cout<<o;
	return 0;
}