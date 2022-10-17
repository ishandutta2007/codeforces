#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1005,mod=998244353;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
int n,m,a[N],d[N];
vector<int> e[N];
bool check(){
	for(int i=1;i<=n;i++)if(a[i])return 0;
	return 1;	
}
void upd(){
	static int b[N];
	for(int i=1;i<=n;i++)b[i]=0;
	for(int x=1;x<=n;x++){
		if(!a[x])continue;
		a[x]--;
		for(int y:e[x])b[y]++;
	}
	for(int i=1;i<=n;i++)a[i]+=b[i];
}
void solve(){
	n=in(),m=in();
	for(int i=1;i<=n;i++)a[i]=in(),e[i].clear(),d[i]=0;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);	
		d[y]++;
	}
	if(check()){
		puts("0");
		return;	
	}
	for(int i=1;i<=m;i++){
		upd();
		if(check()){
			printf("%d\n",i);
			return;	
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(!d[i])q.push(i);	
	}
	int lst=0;
	while(q.size()){
		int x=q.front();q.pop();
		for(int y:e[x]){
			d[y]--,a[y]=add(a[x],a[y]);
			if(!d[y])q.push(y);	
		}
		lst=add(a[x],m);
	}
	printf("%d\n",lst);
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}