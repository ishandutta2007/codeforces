#include<bits/stdc++.h>
using namespace std;
const int N = 1009;
int T;
int a[N],cnt;
string s;
bool cmp(int x,int y){return x>y;}
int main(){
	memset(a,0,sizeof(a));
	scanf("%d",&T);	
	while(T--){
		cin>>s;s='0'+s;cnt=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='1'&&s[i-1]=='0') cnt++;
			if(s[i]=='1') a[cnt]++;
		}	
		sort(a+1,a+cnt+1,cmp);
		int ans=0;
		for(int i=1;i<=cnt;i+=2) ans+=a[i];
		printf("%d\n",ans);
		for(int i=1;i<=cnt;i++) a[i]=0;
	}
	return 0;
}