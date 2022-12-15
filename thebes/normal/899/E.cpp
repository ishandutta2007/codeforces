#include <bits/stdc++.h>
using namespace std;

const int MN = 200005;
int ds[MN], N, arr[MN], a[MN][2], sz[MN], ans, i; struct pii{int f, s;};
int ld(int x){return ds[x]=(x!=ds[x])?ld(ds[x]):x;}
struct pq{bool operator()(const pii&i,const pii&j){
	return(i.f==j.f)?(ld(i.s)>ld(j.s)):i.f<j.f;}};
priority_queue<pii,vector<pii>,pq> q;
pii pr(int f,int s){pii z={f,s}; return z;}
bitset<MN> use; int j, p;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&arr[i]), ds[i]=i;
	for(i=1;i<=N;i=j){
		for(j=i;j<=N&&arr[i]==arr[j];j++){}
		a[i][0] = p; a[i][1] = j; p = i; sz[i]=j-i;
		q.push(pr(j-i,i));
	}
	arr[N+1] = -1;
	while(!q.empty()){
		pii _ = q.top(); q.pop();
		if(use[ld(_.s)]) continue;
		use[ld(_.s)] = 1; int x = ld(_.s); ans++;
		if(arr[a[x][0]]==arr[a[x][1]]){
			int l = ld(a[x][0]), r = ld(a[x][1]);
			sz[l] += sz[r]; a[l][1]=a[r][1]; a[r][0]=a[l][0];
			ds[r] = l; q.push(pr(sz[l],l));
		}
		else{
			int l = ld(a[x][0]), r = ld(a[x][1]);
			a[l][1] = a[x][1]; a[r][0] = a[x][0];
		}
	}
	printf("%d\n",ans);
	return 0;
}