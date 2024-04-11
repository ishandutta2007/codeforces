#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int MN = 1e5+5;
int N, M, i, j, x0, y0, x, y, fl;
pii a[MN], b[MN], pre;
vector<pii> hull;
inline bool cp(pii i,pii j){return 1LL*i.F*j.S-1LL*i.S*j.F>0;}

int main(){
	scanf("%d%d%d%d",&N,&M,&x0,&y0);
	for(i=1;i<=N;i++){
		scanf("%d%d",&x,&y);
		a[i] = {x, y};
	}
	int mx = 0, my = 0;
	for(i=1;i<=M;i++){
		scanf("%d%d",&x,&y);
		b[i] = {x, y};
		mx = max(mx, x);
		my = max(my, y);
	}
	b[++M] = {mx, 0};
	b[++M] = {0, my};
	sort(b+1,b+M+1,[](pii i,pii j){return i.F<j.F;});
	for(i=1;i<=M;i++){
		while(hull.size()>=2){
			int sz = (int)hull.size()-1;
			pii lst = {hull[sz].F-hull[sz-1].F,hull[sz].S-hull[sz-1].S};
			pii cur = {b[i].F-hull[sz].F,b[i].S-hull[sz].S};
			if(cp(lst,cur)) hull.pop_back();
			else break;
		}
		hull.push_back(b[i]);
	}
	hull.insert(hull.begin(),{0,hull[0].S});
	sort(a+1,a+N+1,[](pii i,pii j){return i.F<j.F;});
	for(i=1,j=0;i<=N;i++){
		while(j<(int)hull.size()&&hull[j].F<a[i].F) j++;
		if(a[i].F==mx||a[i].S==my) fl = 1;
		else if(j<(int)hull.size()&&j>0){
			pii v1 = {a[i].F-hull[j-1].F,a[i].S-hull[j-1].S};
			pii v2 = {hull[j].F-hull[j-1].F,hull[j].S-hull[j-1].S};
			if(!cp(v1,v2)) fl = 1;
		}
		else fl = 1;
	}
	printf("%s\n",fl?"Max":"Min");
	return 0;
}