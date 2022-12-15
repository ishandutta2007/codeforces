#include <bits/stdc++.h>
#define mt make_tuple
using namespace std;

const int MN = 300005;
typedef tuple<int,int,int> T;
int p[MN], tmp[MN], N, M, i, x, y, w;
vector<T> vec; bitset<MN> s; queue<int> upd;
bool cmp(T i,T j){return((get<2>(i))<(get<2>(j)));}

int main(){
	for(scanf("%d%d",&N,&M),i=0;i<M;i++){
		scanf("%d%d%d",&x,&y,&w);
		vec.push_back(mt(x,y,w));
	}
	sort(vec.begin(),vec.end(),cmp);
	memset(tmp, -1, sizeof(tmp)); i=0;
	for(auto t : vec){
		x = get<0>(t), y = get<1>(t), w = get<2>(t);
		if(w != i){
			i = w;
			while(!upd.empty()){
				int _ = upd.front(); upd.pop();
				s[_] = 0; p[_] = max(p[_],tmp[_]);
				tmp[_] = -1;
			}
		}
		if(!s[y]){s[y]=1; upd.push(y);}
		tmp[y] = max(tmp[y], p[x]+1);
	}
	while(!upd.empty()){
		int _ = upd.front(); upd.pop();
		s[_] = 0; p[_] = max(p[_],tmp[_]);
		tmp[_] = -1;
	}
	int ans = 0;
	for(i=1;i<=N;i++) ans = max(ans,p[i]);
	printf("%d\n",ans);
	return 0;
}