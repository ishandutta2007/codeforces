#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,m,ans;
int a[N],lap[N];
pair<int,int> q[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),lap[a[i]]=i;
	for (int i=1;i<=n;i++)
		if (lap[a[i]]!=i&&lap[a[i]]>q[m].second)
			q[++m]=pair<int,int>(i,lap[a[i]]);
	int l=1;
	for (int i=2;i<=m+1;i++)
		if (i==m+1||q[i].first>q[i-1].second){
			ans+=q[i-1].second-q[l].first+1;
			int p=l,s=2;
			for (int j=l+1;j<i;j++)
				if (q[j].first>q[p].second)
					++s,p=j-1;
			ans-=s+(l+1!=i);
			l=i;
		}
	cout<<ans<<endl;
}