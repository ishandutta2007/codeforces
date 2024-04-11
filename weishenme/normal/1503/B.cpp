#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
int n,id;
vector<pii> v1,v2;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if ((i+j)%2==0)v1.push_back(mp(i,j));
			else v2.push_back(mp(i,j));
	for (int i=1;i<=n*n;i++){
		scanf("%d",&id);
		if (id!=1){
			if (!v1.size()){
				printf("%d %d %d\n",id==2?3:2,v2.back().fi,v2.back().se);
				v2.pop_back();
			}
			else {
				printf("1 %d %d\n",v1.back().fi,v1.back().se);
				v1.pop_back();
			}
		}
		else {
			if (!v2.size()){
				printf("3 %d %d\n",v1.back().fi,v1.back().se);
				v1.pop_back();
			}
			else {
				printf("2 %d %d\n",v2.back().fi,v2.back().se);
				v2.pop_back();
			}
		}
		fflush(stdout);
	}
}