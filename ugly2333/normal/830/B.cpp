//CF 830B
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
vector<int> v[111111];
int sz[111111];
int main()
{
	int n,t,i,j,s,x,p;
	LL ans;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		v[x].push_back(i);
		sz[x]++;
	}
	t=n;
	x=1;
	ans=0;
	while(t>0){
		p=0;
		ans+=(LL)t;
		//cout<<t<<endl;
		while(t>0&&p<=n){
			while(!sz[x]){
				x++;
			}
			s=0;
			for(i=0;i<sz[x];i=i+1){
				if(v[x][i]>p){
					p=v[x][i];
					s++;
					t--;
				}
			}
			sz[x]-=s;
			if(sz[x]||s==0)
				break;
		}
	}
	cout<<ans<<endl;
	return 0;
}