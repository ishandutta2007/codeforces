#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e5+5;
int n,k;
int a[N],b[N],t[N];
int mark[N];
vector<int> v[N];
void solve(){
	n=in();
	for(int i=0;i<=n+1;i++)v[i].clear();
	for(int i=1;i<=n;i++)
		b[i]=in(),v[b[i]].push_back(i);
	k=0;
	for(int i=1;i<=n;i++)if(b[i]>i)k=i;
	int p;
	if(v[0].size())p=0;
	else p=n+1;
	printf("%d\n",k);
	vector<int> ans;
	while(ans.size()<n){
		for(int i:v[p])if(!v[i].size())ans.push_back(i);
		for(int i:v[p])if(v[i].size())ans.push_back(i);
		p=ans.back();
	}
	for(int i:ans)printf("%d ",i);
	puts("");
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}