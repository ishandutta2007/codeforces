#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;

int k,x[N],y[N];
int solve(){
	int n;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<n;i++){
		bool f=1;
		for(int j=0;j<n;j++){
			int a=abs(x[i]-x[j])+abs(y[i]-y[j]);
			if(a>k)f=0;
		}
		if(f)return 1;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("in.txt","r",stdin);
	int _;cin>>_;
	while(_--)
	cout<<solve()<<endl; 
	return 0;
}