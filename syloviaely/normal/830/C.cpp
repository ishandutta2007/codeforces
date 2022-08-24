#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct atom{
	int l,r,w;
};
vector<atom>B; 
vector<long long>A;
int x[110],n;
long long w[11000000];
long long K;
int main(){
	scanf("%d%I64d",&n,&K); A.push_back(1);
	for (int j=1;j<=n;j++){
		scanf("%d",&x[j]); int m=x[j]-1;
		for (int ne,i=1;i<=m;i=ne+1){
			ne=m/(m/i); A.push_back(ne+1);
			B.push_back((atom){i,ne+1,m/i});
		}
	}
//	for (int i=0;i<B.size();i++) cout<<B[i].l<<" "<<B[i].r<<" "<<B[i].w<<endl;
	A.push_back(1e12);
	sort(A.begin(),A.end());
	int tot=unique(A.begin(),A.end())-A.begin();
	A.resize(tot);
	for (int i=0;i<B.size();i++){
		int L=lower_bound(A.begin(),A.end(),B[i].l)-A.begin();
		int R=lower_bound(A.begin(),A.end(),B[i].r)-A.begin();
		w[L]+=B[i].w; w[R]-=B[i].w;
	}
	long long b=0,ans=0;
	for (int i=1;i<=n;i++) b+=x[i];
	b+=K;
//	for (int i=0;i<A.size();i++) cout<<A[i]<<" "; cout<<endl;
	for (int i=0;i<A.size();i++){
		if (i) w[i]+=w[i-1];
		long long k=w[i]+n;
		long long lim=b/k;
//		cout<<k<<" "<<b<<endl;
		if (lim<A[i]) continue;
		lim=min(lim,A[i+1]);
		ans=max(ans,lim);
	}
//	for (int i=0;i<A.size();i++) cout<<w[i]<<" "; cout<<endl;
	cout<<ans<<endl;
	return 0;
}