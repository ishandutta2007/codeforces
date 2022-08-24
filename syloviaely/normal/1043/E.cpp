#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int N=310000;
vector<int> go[N];
int A[N],B[N],n,m;
int a[N];
int compare(int k1,int k2){
	return B[k1]<B[k2];
}
int ra[N];
long long pre[N];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&A[i],&B[i]); B[i]-=A[i];
		a[i]=i;
	}
	sort(a+1,a+n+1,compare);
	for (int i=1;i<=n;i++) ra[a[i]]=i;
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+B[a[i]];
	long long tot=0;
	for (int i=1;i<=n;i++) tot+=A[i];
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2);
		go[k1].pb(k2); go[k2].pb(k1);
	}
	for (int now=1;now<=n;now++){
		long long k1=tot-A[now]+1ll*A[now]*(n-1);
		int where=ra[now];
		k1+=pre[where-1]+1ll*B[now]*(n-where);
		//cout<<k1<<" "<<where<<endl;
		for (int i=0;i<go[now].size();i++){
			int j=go[now][i];
			k1-=A[now]+A[j]+min(B[now],B[j]);
		}
		printf("%lld ",k1);
	}
}