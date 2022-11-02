#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,q,a[1510][1510],cnt[1510],ans[1510][1510];
vector<pair<int,int> > A[1510],B[1510],st;
int tim,vis[1510*1510];
int main() {
	//freopen("2.txt","r",stdin);
	read(n),read(q);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) read(a[i][j]);
	for (int i=n;i>=1;i--) {
		for (int j=n;j>=1;j--) {
			A[j].swap(B[j]);
			B[j].clear();
		}
		for (int j=n;j>=1;j--) {
			st.clear();
			for (pair<int,int> tmp : A[j]) st.push_back(make_pair(tmp.first+1,tmp.second));
			for (pair<int,int> tmp : B[j+1]) st.push_back(make_pair(tmp.first+1,tmp.second));
			for (pair<int,int> tmp : A[j+1]) st.push_back(make_pair(tmp.first+1,tmp.second));
			st.push_back(make_pair(1,a[i][j]));
			if (i<n&&j<n&&ans[i+1][j]==ans[i][j+1]) {
				st.push_back(make_pair(ans[i+1][j]+1,a[i+ans[i+1][j]][j+ans[i+1][j]]));
			}
			sort(st.begin(),st.end());
			ans[i][j]=min({n-i+1,n-j+1,ans[i+1][j]+1,ans[i][j+1]+1,ans[i+1][j+1]+1});
			tim++;
			int cnt=0;
			for (pair<int,int> tmp : st) {
				if (vis[tmp.second]==tim) continue;
				if (cnt==q) {
					ans[i][j]=min(ans[i][j],tmp.first-1);
					break;
				}
				vis[tmp.second]=tim;
				B[j].push_back(tmp);
				cnt++;
			}
		}
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cnt[ans[i][j]]++;
	for (int i=n;i>=1;i--) cnt[i]+=cnt[i+1];
	for (int i=1;i<=n;i++) printf("%d\n",cnt[i]);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/