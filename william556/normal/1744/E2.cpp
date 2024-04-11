// LUOGU_RID: 90774136
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
vector<int> v1,v2;
void solve(){
	int a=in(),b=in(),c=in(),d=in();
	v1.clear(),v2.clear();
	for(int i=1;i*i<=a;i++){
		if(a%i==0)v1.push_back(i),v1.push_back(a/i);	
	}
	for(int i=1;i*i<=b;i++){
		if(b%i==0)v2.push_back(i),v2.push_back(b/i);	
	}
	long long e=1ll*a*b;
	int ans=0;
	for(int x:v1){
		for(int y:v2){
			long long u=1ll*x*y;
			if(c/u==a/u)continue;
			long long v=e/u;
			if(d/v==b/v)continue;
			cout<<u*(c/u)<<' '<<v*(d/v)<<endl;
			return;
		}
	}
	cout<<-1<<' '<<-1<<endl;
}
int main(){
//	freopen("in.txt","r",stdin);
	int t=in();
	while(t--)solve();
	return 0;
}