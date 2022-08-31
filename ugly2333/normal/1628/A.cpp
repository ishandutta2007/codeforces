//CF1628A
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
int n,a[N];
int s[N],t[N];
vector<int> v;
int main()
{
	int T,i,j,x,y;
	scanf("%d",&T);
	while(T--){
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i),s[a[i]]++;
		x=0,y=0;
		while(s[x]){
			x++;
		}
		j=0;
		for(i=1;i<=n;i++){
			t[a[i]]++;
			while(t[y]){
				y++;
			}
			if(x==y){
				v.push_back(x);
				while(j<i){
					j++;
					t[a[j]]--;
					s[a[j]]--;
					if(s[a[j]]==0)
						x=min(x,a[j]);
				}
				y=0;
			}
		}
		printf("%d\n",v.size());
		for(i=0;i<v.size();i++)
			printf("%d ",v[i]);
		printf("\n");
		v.clear();
	}
	return 0;
}