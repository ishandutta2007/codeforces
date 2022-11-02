#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int T,n,a[N];
char s[N];


int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=0;i<=n;i++) a[i]=0;
		for(int i=1;i<=n;i++) a[i]+=s[i]-'0';
		scanf("%s",s+1);
		for(int i=1;i<=n;i++) a[i]+=s[i]-'0';
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==2){
				if(i>1&&a[i-1]==0) a[i-1]=1;
				else if(i<n&&a[i+1]==0) a[i+1]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			if(a[i]==1) ans+=2;
		}
		printf("%d\n",ans);
	}
	return 0;
}