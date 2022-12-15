#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> T;
const int MN = 1e5+5;
tuple<int,int,int> e[MN];
int n, m, i, x, y, flag=1, sp[MN], nxt, w[MN];
pair<int,int> ans[MN];

int main(){
	for(i=1;i<MN;i++) w[i]=1<<30;
	for(scanf("%d%d",&n,&m),i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		e[i] = {x,y,i}; sp[i]=y;
	}
	sort(e+1, e+m+1, [](T i,T j){return(get<1>(i)==get<1>(j))?get<0>(i)<get<0>(j):get<1>(i)>get<1>(j);});
	nxt=1; x=2; y=3;
	for(i=1;i<=m;i++){
		if(get<1>(e[i])){
			ans[get<2>(e[i])]={1,++nxt};
			w[nxt] = get<0>(e[i]);
		}
		else{
			ans[get<2>(e[i])]={x,y};
			if(get<0>(e[i])<max(w[x],w[y])){
				printf("-1\n");
				return 0;
			}
			if(x+1==y) y++,x=2;
			else x++;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}