// Author : WangZhikun
// 2018-7-13

#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll mod = (1e9)+7;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll gmin(ll a,ll b){return a<b?a:b;}
ll gmax(ll a,ll b){return a>b?a:b;}
ll exgcd(ll a,ll b,ll &x,ll &y){
	ll d = a;
	if(b!=0){d = exgcd(b,a%b,y,x);y-=(a/b)*x;}else{x = 1; y = 0;}
	return d;
}
ll inv(ll a){ll d,x,y;d = exgcd(a,mod,x,y);return d==1 ? (x+mod)%mod : -1;}
ll pow(ll a,ll b){ll an = 1;
	for(int i=0;i<40;i++){if(b&1){an*=a;an%=mod;}a*=a;a%=mod;b>>=1;}
	return an;
}

int n,cur,ans = 0,cu = 0;

struct aa{
	int v,p;
} arr[200020];

bool cmp(aa a,aa b){
	return a.v<b.v;
}
queue<aa> emp;
queue<int> fal;
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cur;
		arr[i] = (aa){cur,i};
	}
	sort(arr,arr+n,cmp);
	for(int i=0;i<n;i++){
		int suc = 0;
		if(!emp.empty()){
			aa a = emp.front();
			if(a.v<arr[i].v){
				emp.pop();
				suc = 1;
			}
		}
		ans+=suc;
		emp.push((aa){arr[i].v,arr[i].p});
	}
	cout<<ans<<endl;
	return 0;
}