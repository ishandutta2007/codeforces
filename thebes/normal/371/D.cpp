#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int N, M, c[MN], k[MN], i, x, y, ans;
set<int> s;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&c[i]),s.insert(i);
	for(scanf("%d",&M);M>0;M--){
		scanf("%d",&x);
		if(x == 1){
			scanf("%d%d",&x,&y);
			auto it = s.lower_bound(x);
			set<int>::iterator it2;
			while(it != s.end() && y){
				int rem = c[*it]-k[*it];
				k[*it] += min(y,rem);
				y -= min(y,rem);
				it2 = it; it++;
				if(k[*it2] == c[*it2])
					s.erase(it2);
			}
		}
		else if(x == 2)
			scanf("%d",&x),printf("%d\n",k[x]);
	}
	return 0;
}