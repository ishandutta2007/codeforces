#include<bits/stdc++.h>
using namespace std;
int n,m,tot;double k;
struct pp{string s;int exp;}a[109];
map<string,int >mp;
bool cmp(pp x,pp y){
	return x.s<y.s;
}
int main(){
	mp.clear();
	scanf("%d%d%lf",&n,&m,&k);tot=0;
	int  p=ceil(k*1000.0);
	for(int i=1;i<=n;i++){
		string x;int e;
		cin>>x>>e;
		if(e*p-100000>=0){
			a[++tot].s=x,a[tot].exp=e*p/1000;
			mp[x]=1;
		}
	}
	for(int i=1;i<=m;i++){
		string x;
		cin>>x;
		if(mp[x]==1) continue;
		a[++tot].s=x;
		a[tot].exp=0;
	}
	sort(a+1,a+tot+1,cmp);
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++){
		cout<<a[i].s<<" "<<a[i].exp<<endl;
	}
	return 0;
}