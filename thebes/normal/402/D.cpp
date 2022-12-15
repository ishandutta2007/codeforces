#include <bits/stdc++.h>
using namespace std;

const int MN = 5005;
int gcd(int a,int b){return(a)?gcd(b%a,a):b;}
int n, m, i, j, x, arr[MN]; set<int> s;
map<int,int> mp;
int f(int n, int st){
	if(n==1) return 0;
	for(int i=st;i<=sqrt(n+0.0);i++){
		if(n%i==0){
			if(s.find(i)!=s.end()) return f(n/i,i)-1;
			else return f(n/i,i)+1;
		}
	}
	if(s.find(n)!=s.end()) return -1;
	else return 1;
}

int main(){
	for(scanf("%d%d",&n,&m),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<=m;i++){
		scanf("%d",&x);
		s.insert(x);
	}
	for(i=n;i>=1;i--){
		for(x=0,j=1;j<=i;j++)
			x=gcd(x,arr[j]);
		if(!mp.count(x)) mp[x]=f(x,2);
		if(mp[x]<=0){
			for(j=1;j<=i;j++)
				arr[j]/=x;
		}
	}
	int ans = 0;
	for(i=1;i<=n;i++)
		ans += f(arr[i],2);
	printf("%d\n",ans);
	return 0;
}