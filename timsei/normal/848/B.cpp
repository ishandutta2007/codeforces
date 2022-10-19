#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define Pair pair<int,int>

const int N = 100005;

struct NODE {
	int x , y , id , t;
	friend bool operator < (NODE xxx , NODE yyy) {
		return (xxx.x == yyy.x) ? xxx.y > yyy.y : xxx.x < yyy.x;
	}
}ind , tmp;

map<int,vector<NODE> >M1 , M2;

vector<NODE> xx , yy;

int n , w , h , g , p , t;

Pair ans[N];

int main() {
	scanf("%d%d%d",&n,&w,&h);
	for(int i = 1;i <= n;i ++) {
		scanf("%d%d%d",&g , & p , &t);
		int x , y , id;
		if(g == 1) {
			x = p;
			y = 0;
			id = i;
		}
		else {
			x = 0;
			y = p;
			id = i;
		}
		tmp.x = x; tmp.y = y; tmp.id = i;
		M1[p - t].push_back(tmp);
		if(g == 1) tmp.y = h;
		else tmp.x = w;
		M2[p - t].push_back(tmp);
	}
	for(map<int,vector<NODE> > ::iterator it = M1.begin();it != M1.end(); it ++) {
		xx = it->second;
		yy = M2[it -> first];
		sort(xx.begin() , xx.end());
		sort(yy.begin() , yy.end());
		for(int i = 0;i <(int) xx.size();i ++) {
			ans[xx[i].id] = make_pair(yy[i].x , yy[i].y);
		}
	}
	for(int i = 1;i <= n;i ++) printf("%d %d\n", ans[i].first , ans[i].second);
}