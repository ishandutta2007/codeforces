#include<bits/stdc++.h>
using namespace std;

const int maxn=2007;
int n,a[maxn],b[maxn],c[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i];
	}
	for (int i=1;i<=n;++i){
		for (int j=n;j>i;--j){
			if (a[j]==a[i]){
				b[i]=j;
				break; 
			}
		}
		for (int j=1;j<i;++j){
			if (a[j]==a[i]){
				c[i]=j;
				break;
			}
		}
	}
	set<int> s;
	s.clear();
	int i=1,j;
	for (j=n;j>0;--j){
		if (s.find(a[j])!=s.end()) break;
		s.insert(a[j]);
	}
	if (j==0){
		puts("0");
		return 0;
	}
	int ans=j-i+1;
	while (i<=n&&j<=n){
		if (c[i]!=0){
			break;
		}
		j=max(b[i],j);
		i++;
		ans=min(ans,j-i+1);
	}
	cout<<ans<<endl;
	return 0;
}