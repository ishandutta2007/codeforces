using namespace std;
#include<bits/stdc++.h>
#include<map>
#define N 100001
int S[N],a[N],b[N],num[N];
int n,m,tot;
map<int,int>M;
map<int,int>hh;
int ans;
int main() {
	cin>>m>>n;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=m;i++) S[i]=S[i-1]+a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=m;i++) {
		int it=b[1]-S[i];
		if(hh.count(it)) continue;
		M.clear();hh[it]=1;tot=0;
		for(int j=1;j<=m;j++) {
			M[S[j]+it]++;
		}
		bool f=0;
		for(int k=1;k<=n;k++) {
			if(!M.count(b[k])||!(M[b[k]]--)) {
				f=1;break;
			}
		}
		if(!f) ans++;
	}
	cout<<ans<<endl;
}