#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
int Add(int x,int y){
	int z=0,v=1;
	for (;x||y;){
		z+=((-x+y)%k+k)%k*v;
		x/=k; y/=k; v*=k;
	}
	return z;
}
int y=233;
bool check(int x){
	cout<<x<<endl;
	cin>>x;
	return x;
}
void solve(){
	scanf("%d%d",&n,&k);
	if (check(0)) return;
	for (int i=1;i<n;i++)
		if (check(Add(i-1,i)))
			return;
	assert(0);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}