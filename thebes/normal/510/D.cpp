#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){return(!a)?b:gcd(b%a,a);}
int n, l[303], c[303], i; map<int,int> m;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&l[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&c[i]);
	m[0]=0;
	for(i=1;i<=n;i++){
		for(auto v : m){
			int p=gcd(v.first,l[i]);
			int o=(m.count(p))?m[p]:1<<30;
			m[p]=min(o,v.second+c[i]);
		}
	}
	if(m.count(1)) printf("%d\n",m[1]);
	else printf("-1\n");
	return 0;
}