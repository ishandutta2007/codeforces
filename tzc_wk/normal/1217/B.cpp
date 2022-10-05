#include <bits/stdc++.h>
using namespace std;
int n,x;
struct node{
	int d,s;
} a[105],b[105];
inline bool cmp1(node a,node b){
	return a.d-a.s>b.d-b.s;
}
inline bool cmp2(node a,node b){
	return a.d>b.d;
}
inline void solve(){
	cin>>n>>x;
	for(int i=1;i<=n;i++)	cin>>a[i].d>>a[i].s,b[i]=a[i];
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp2);
	int dif=a[1].d-a[1].s,mx=b[1].d;
	if(x<=mx){
		puts("1");
		return;
	}
	if(dif<=0){
		puts("-1");
		return;
	}
	int need=x-mx;
	if(need%dif==0){
		cout<<need/dif+1<<endl;
	}
	else{
		cout<<need/dif+2<<endl;
	}
}
int main(){
	int T;cin>>T;
	while(T--)	solve();
	return 0;
}