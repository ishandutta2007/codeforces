#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)

using namespace std;

const int maxn=1000007;
int n;
vector<int> u[70];
bool vis[maxn];
long long a[maxn];

int calc(long long u){
	int _=0;
	while (!(u&1)){
		_++;
		u>>=1;
	}
	return _;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		u[calc(a[i])].push_back(i);
	}
	int j=-1;
	for (int i=0;i<70;++i){
		if (j==-1||u[j].size()<u[i].size()){
			j=i;
		}
	}
	for (auto c:u[j]){
		vis[c]=1;
	}
	cout<<n-u[j].size()<<endl;
	rep1(i,n) if (!vis[i]) cout<<a[i]<<" ";
	return 0;
}