#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
ll n,s,p[100010],deg[100010] = {0},belong[100010] = {0};
stack<int> pw[100010];
int main() {
	read(n);read(s);
	if(s<n*2-1 || s>n*(n+1)/2){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	ll cc,left,cu = 1e18;
	for(cc=1;cu>s;cc++){
		left = n,cu = 0;
		for(ll i=1,j=1;left;i*=cc,j++){
			//cout<<i<<' '<<j<<' '<<left<<endl;
			i = min(i,left);
			left-=i;
			cu+=i*j;
		}
	}
	cc-=1;
	//cout<<cc<<endl;
	ll req = n*(n+1)/2-s,cok = 1;
	belong[1] = 1;
	for(int i=2;i<=n;i++){
		belong[i] = i;
		pw[i-1].push(i-1);
		deg[i-1] = 1;
		p[i] = i-1;
	}
	
	for(int i=n;req;i--){
		cok = max(cok,i-req-1);
		
		while(pw[cok].empty())++cok;
		while(belong[pw[cok].top()]!=cok)pw[cok].pop();
		//cout<<cok<<endl;
		req-=i-cok-1;
		int c = pw[cok].top();
		deg[c]++;
		pw[cok+1].push(i);
		belong[i] = cok+1;
		p[i] = c;
		deg[i] = 0;
		if(deg[c] == cc)pw[cok].pop();
	}/*
	cout<<req<<endl;
	int su = 0;
	for(int i=1;i<=n;i++){
		cout<<belong[i]<<' ';
		su+=belong[i];
	}
	cout<<endl;
	cout<<su<<endl;*/
	for(int i=2;i<=n;i++){
		
		cout<<p[i]<<' ';
	}
	cout<<endl;
	return 0;
}