#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[105];
bool flag;
inline void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	flag=0;
	a[n+1]=a[n];
	for(int i=1;i<=n;i++){
		m+=a[i];
		m-=max(a[i+1]-k,0);
		if(m<0){
			flag=1;
			break;
		}
	}
    if(flag)	puts("NO");
    else		puts("YES");
}
int main(){
	int T;cin>>T;
	while(T--)	solve();
	return 0;
}