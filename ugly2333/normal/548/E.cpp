//
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 5e5+5;
int n=5e5,f[N],s[N];
vector<int> v[N];
int q,a[N],c[N];
int main()
{
	int i,j,t;
	LL ans;
	for(i=1;i<=n;i=i+1){
		if(i==1)
			f[i]=1;
		for(j=i;j<=n;j=j+i){
			v[j].push_back(i);
			if(j>i)
				f[j]-=f[i];
		}
	}
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	ans=0;
	while(q--){
		scanf("%d",&i);
		t=v[a[i]].size();
		if(c[i]){
			c[i]=0;
			i=a[i];
			for(j=0;j<t;j=j+1)
				ans-=f[v[i][j]]*(--s[v[i][j]]);
		}
		else{
			c[i]=1;
			i=a[i];
			for(j=0;j<t;j=j+1)
				ans+=f[v[i][j]]*(s[v[i][j]]++);
		}
		cout<<ans<<endl;
	}
	return 0;
}