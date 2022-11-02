#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int T,n;
char s[N];




int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);		
		n=strlen(s+1);
		int ans=2;
		int flag=1;
		for(int i=1;i<=n;i++)
			if(s[i]=='0') flag=0;
		if(flag) ans=min(ans,0);
		flag=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'&&flag==1){
				flag=-1;
			}
			else{
				if(s[i]=='0'&&flag==-1&&s[i-1]!='0') flag=0;
			}
		}
		if(flag!=0) ans=min(ans,1);
		printf("%d\n",ans);
	}
	return 0;
}