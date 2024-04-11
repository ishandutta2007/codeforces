// Author: Zhikun
// 2018.07.18

#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define N 200020

using namespace std;
typedef long long ll;

int n,a[N],bc[N],size[N],bysz[N] = {0};
struct P{
	int v,p;
}b[N];
bool cmp(P a,P b){return a.v<b.v;}
int find(int x){
	return bc[x] == x?x:bc[x] = find(bc[x]);
}
void mrg(int a,int b){
	bysz[size[find(a)]]-=1;bysz[size[find(b)]]-=1;
	size[find(b)] += size[find(a)];
	size[find(a)] = 0;
	bc[find(a)] = find(b);
	bysz[size[find(b)]]+=1;
}
int main(){
	cin>>n;
	a[0] = 1e9+7;
	a[n+1] = 1e9+7;
	for(int i=0;i<=200010;i++)bc[i] = i,size[i] = 1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i].v = a[i];
		b[i].p = i;
	}
	sort(b+1,b+n+1,cmp);
	int cans = 0,ans = 0,mloc = 0;
	for(int i=1;i<=n;i++){
		bysz[1]+=1;
		cans = b[i].v+1;
		if(a[b[i].p-1]<cans){
			mrg(b[i].p+1,b[i].p);
		}
		if(a[b[i].p+1]<cans){
			mrg(b[i].p+1,b[i].p);
		}
		if(bysz[size[find(b[i].p)]]*size[find(b[i].p)] == i){
			if(bysz[size[find(b[i].p)]]>mloc){
				mloc = bysz[size[find(b[i].p)]];
				ans = cans;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}