#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
using namespace std;
#define ll long long
const ll p=163729;
const ll mod=163227661;
int n;
string ans,a;
void deal(){
	ll tmp=1,h1=0,h2=0;int t=0;
	for(int i=0;i<min(ans.size(),a.size());i++){
		h1=(h1+ans[ans.size()-i-1]*tmp)%mod;
		h2=(h2*p+a[i])%mod;
		tmp=(tmp*p)%mod;
		if(h1==h2) t=i+1;
	}
	for(int i=t;i<a.size();i++) ans+=a[i];
}
int main() {
	scanf("%d",&n);
	cin>>ans;
	for(int i=2;i<=n;i++){cin>>a;deal();}
	cout<<ans;
	return 0;
}
//