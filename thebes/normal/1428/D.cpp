#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 1e5+5;
int N, i, j, arr[MN];
vector<pii> ans, pos[4];

int main(){
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&arr[i]);
	}
	for(i=N;i>=1;i--){
		if(arr[i]==0) continue;
		if(arr[i]==1){
			pos[1].pb({i, i});
			ans.pb({i, i});
		}
		else{
			int fnd = 0;
			for(j=arr[i]-1;j>=1;j--){
				if(pos[j].size()){
					if(arr[i]==2){
						ans.pb({i,pos[j].back().S});
						pos[arr[i]].pb({i,pos[j].back().S});
						pos[j].pop_back();
					}
					else{
						ans.pb({i,i});
						ans.pb({pos[j].back().F,i});
						pos[j].pop_back();
						pos[2].push_back({i,i});
					}
					fnd = 1;
					break;
				}
			}
			if(!fnd){
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto v : ans)
		printf("%d %d\n",v.S,v.F);
	return 0;
}