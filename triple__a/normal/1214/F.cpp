#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
const long long INF=1e15;
int a[maxn<<2],b[maxn],pa[maxn<<2],pb[maxn];
int n,m,idx;
long long ans[maxn<<2],cnt;

bool cmp1(const int &u,const int &v){
	return a[u]<a[v];
}

bool cmp2(const int &u,const int &v){
	return b[u]<b[v];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>m>>n;
	memset(ans,0,sizeof(ans));
	for (int i=1;i<=n;++i){
		cin>>a[i+n];
		pa[i+n]=i+n;
	}
	sort(pa+n+1,pa+2*n+1,cmp1);
	for (int i=1;i<=n;++i){
		a[i]=a[i+n]-m;
		pa[i]=pa[i+n]-n;
		a[i+2*n]=a[i+n]+m;
		pa[i+2*n]=pa[i+n]+n;
	}
	for (int i=1;i<=n;++i){
		cin>>b[i];
		pb[i]=i;
	}
	sort(pb+1,pb+n+1,cmp2);
	int j=1;
	for (int i=1;i<=n;++i){
		while (a[pa[j]]<=b[pb[i]]) ++j;
		ans[1]+=b[pb[i]],ans[j-i+1]-=2*b[pb[i]];
	}
	for (int i=1;i<=n;++i){
		ans[1]-=a[pa[i]], ans[i+1]+=a[pa[i]];
	}
	for (int i=2*n+1;i<=3*n;++i){
		ans[i-n+1]+=a[pa[i]],ans[i+1]-=a[pa[i]];
	}
	j=1;
	for (int i=n+1;i<=2*n;++i){
		while (j<=n&&a[pa[i]]>b[pb[j]]) ++j;
		ans[i-n+1]-=a[pa[i]],ans[i-j+2]+=2*a[pa[i]],ans[i+1]-=a[pa[i]];
	}
	for (int i=2;i<=3*n;++i){
		ans[i]+=ans[i-1];
	}
	cnt=INF,idx=-1;
	for (int i=1;i<=2*n+1;++i){
		if (ans[i]<cnt){
			idx=i,cnt=ans[i];
		}
	}
	cout<<cnt<<endl;
	int rec[maxn];
	for (int i=1;i<=n;++i){
		rec[(pa[i+idx-1]-1)%n+1]=pb[i]; 
	}
	for (int i=1;i<=n;++i){
		cout<<rec[i]<<" ";
	}
	return 0;
}