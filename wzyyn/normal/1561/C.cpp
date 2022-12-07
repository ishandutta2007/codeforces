#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;


const int N=100005;
pair<int,int> q[N];
int n;
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,mx=0;
		scanf("%d",&x);
		for (int j=1;j<=x;j++){
			int y;
			scanf("%d",&y);
			mx=max(mx,y+1-(j-1));
		}
		q[i]=pair<int,int>(mx,x);
	}
	sort(q+1,q+n+1);
	int del=0,re=0;
	for (int i=1;i<=n;i++){
		re=max(re,q[i].first-del);
		del+=q[i].second;
	}
	cout<<re<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}