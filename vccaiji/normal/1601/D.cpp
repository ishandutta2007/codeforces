#include<bits/stdc++.h>
using namespace std;
struct pp{
	int a,s;
}t[510000];
bool cmp(pp a,pp b){
	if(max(a.a,a.s)!=max(b.a,b.s)) return max(a.a,a.s)<max(b.a,b.s);
	return a.s<b.s;
}
int n,d;
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) scanf("%d%d",&t[i].s,&t[i].a);
	sort(t+1,t+n+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++)if(d<=t[i].s){
		d=max(d,t[i].a);
		cnt++;
	}
	cout<<cnt;
	return 0;
}