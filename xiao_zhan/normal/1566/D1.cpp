#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,res,a[1050],op[1050],it;

vector< pair<int,int> > v;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		v.clear();
		for(i=1;i<=m;i++){
			scanf("%d",&k);
			v.push_back({k,-i});
		}
		sort(v.begin(),v.end());
		it=0;res=0;
		memset(a,0,sizeof(a));
		for(auto [i,j]:v){
			//printf("a%d %d\n",i,j);
			op[-j]=++it;
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=op[i];j++){
				res+=a[j];
			}
			a[op[i]]=1;
		}
		printf("%d\n",res);
	}
}