#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int n,m,T;
int a[maxn],tot[maxn],tott[maxn],cnt[maxn],cntt[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),cin>>s,s=" "+s;
		for(int i=1;i<=n*m;i++)
			tot[i]=tot[i-1]+(s[i]=='1'),tott[i]=(i<m? 0:tott[i-m])+(s[i]=='1');
		for(int i=1;i<=n*m;i++)
			cnt[i]=(i<m? 0:cnt[i-m])+(tot[i]>(i<m? 0:tot[i-m]));
		for(int i=1;i<=n*m;i++)
			cntt[i]=cntt[i-1]+(tott[i]>0);
		for(int i=1;i<=n*m;i++)
			printf("%d%c",cnt[i]+cntt[i]-(i<m? 0:cntt[i-m]),i==n*m? '\n':' ');
		for(int i=0;i<=n*m;i++)
			tot[i]=tott[i]=cnt[i]=cntt[i]=0;
	}
	return 0;
}