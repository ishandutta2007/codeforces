#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
int n;
int p[100001];
ll s[100001];
ll a[100001];
int h[100001];
ll mini[100001];
vector<int>c[100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	h[1]=1;
	for(int i=2; i<=n ;i++){
		cin >> p[i];
		h[i]=h[p[i]]+1;
		c[p[i]].push_back(i);
	}
	ll sum=0;
	for(int i=1; i<=n ;i++){
		cin >> s[i];
		mini[i]=1e18;
	}
	a[1]=s[1];
	for(int i=n; i>=1 ;i--){
		if(s[i]==-1){
			if(c[i].empty()) a[i]=0;
			else{
				a[i]=mini[i]-s[p[i]];
				s[i]=s[p[i]]+a[i];
				for(auto ch:c[i]) a[ch]=s[ch]-s[i];
			}
		}
		else{
			mini[p[i]]=min(mini[p[i]],s[i]);
		}
	}
	for(int i=1; i<=n ;i++){
		if(a[i]<0) return cout << "-1\n",0;
		sum+=a[i];
	}
	cout << sum << endl;
}