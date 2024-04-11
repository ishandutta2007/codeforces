#include<bits/stdc++.h>
using namespace std;

const int maxn=1007;
long long ans=0;
string s[maxn];
int a[maxn];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i){
		cin>>s[i];
	}
	for (int i=0;i<k;++i){
		scanf("%d",&a[i]);
	}
	for (int i=0;i<k;++i){
		int ret[7];
		memset(ret,0,sizeof(ret));
		for (int j=1;j<=n;++j){
			ret[s[j][i]-'A']++;
		}
		sort(ret,ret+5);
		ans+=ret[4]*a[i];
	}
	cout<<ans<<endl;
	return 0;
}