#include<bits/stdc++.h>
using namespace std;
int pre[200010];
void init(int x){
	for(int i = 1; i <= x; i ++)
		pre[i] = i;
}
int getroot(int x){
	if(x == pre[x])
		return x;
	return pre[x] = getroot(pre[x]);
}
void Union(int a, int b){
	int u1,u2;
	u1 = getroot(a);
	u2 = getroot(b);
	if(u1 == u2)
		return;
	else if(u1 < u2)
		pre[u1] = u2;
	else
		pre[u2] = u1;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	int n,m,a,b,c,ans=0;
	cin >> n >> m;
	init(n);
	while(m--){
		cin >> b >> c; 
		if(getroot(b) == getroot(c)){
			ans++;
		}
		else{
			Union(b,c);
		} 
	}
	cout<<ans<<endl;
	return 0;
	
}