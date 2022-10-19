#include<bits/stdc++.h>
using namespace std;
int T,n,num[300100];
bool lok[300100],rok[300100],ok;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),lok[0]=rok[n+1]=true;
		for(int i=1;i<=n;i++)scanf("%d",&num[i]);
		for(int i=1;i<=n;i++)lok[i]=(lok[i-1]&(num[i]>=i-1));
		for(int i=n;i;i--)rok[i]=(rok[i+1]&(num[i]>=n-i));
		ok=false;
		for(int i=1;i<=n;i++)if(lok[i]&&rok[i])ok=true;
		puts(ok?"Yes":"No");
	}
	return 0;
}