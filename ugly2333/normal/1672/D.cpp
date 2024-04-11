//CF1672A
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
int n,a[N],b[N];
map<int,int> mp;
int main()
{
	int T,i,j,k,f;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++)
			scanf("%d",b+i);
		mp.clear();
		i=n,j=n;
		f=1;
		while(j){
			while(a[i]!=b[j]&&f){
				if(mp[a[i]]>0){
					mp[a[i]]--;
					i--;
				}
				else{
					f=0;
				}
			}
			if(!f)
				break;
			for(k=j;b[k]==b[j];k--)
				mp[b[j]]++;
			j=k;
		}
		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}