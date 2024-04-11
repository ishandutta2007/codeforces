#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		cin>>s,n=s.size(),m=0;
		for(int i=1;i<=n;i++)
			if(s[i-1]=='1'){
				int j=i;
				while(j<n&&s[j]=='1')
					j++;
				a[++m]=j-i+1,i=j;
			}
		sort(a+1,a+1+m);
		for(int i=m;i>=1;i-=2)
			ans+=a[i];
		printf("%d\n",ans);
	}
	return 0;
}