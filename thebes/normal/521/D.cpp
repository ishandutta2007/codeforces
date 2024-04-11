#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second

const int MN = 1e5+5;
int N, M, K, i, j, x, y, w, c[MN], nxt;
struct hmm{int x, y, w;};
vector<hmm> a[MN], b[MN];
struct idk{ll n, d, id, t;}arr[MN];
vector<pii> ans;

int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(i=1;i<=N;i++)
		scanf("%d",&c[i]);
	for(i=1;i<=M;i++){
		scanf("%d%d%d",&x,&y,&w);
		if(x==1) a[y].push_back({w,i,x});
		else if(x==2) b[y].push_back({w,i,x});
		else arr[++nxt] = {w-1,1,i,x};
	}
	for(i=1;i<=N;i++){
		sort(a[i].begin(),a[i].end(),[](hmm i,hmm j){return i.x>j.x;});
		if(a[i].size()&&a[i][0].x>=c[i]){
			b[i].push_back({a[i][0].x-c[i],a[i][0].y,a[i][0].w});
		}
	}
	for(i=1;i<=N;i++){
		sort(b[i].begin(),b[i].end(),[](hmm i,hmm j){return i.x>j.x;});
		ll cur = c[i];
		for(auto v : b[i]){
			arr[++nxt] = {v.x, cur, v.y, v.w};
			cur += v.x;
		}
	}
	sort(arr+1,arr+nxt+1,[](idk i,idk j){return i.n*j.d>j.n*i.d;});
	for(i=1;i<=min(nxt,K);i++){
		ans.push_back({arr[i].id,arr[i].t});
	}
	sort(ans.begin(),ans.end(),[](pii i,pii j){return i.S<j.S;});
	printf("%d\n",(int)ans.size());
	for(auto v : ans)
		printf("%d ",v);
	printf("\n");
	return 0;
}