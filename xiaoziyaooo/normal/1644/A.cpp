#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>s;
		int a=0,b=0,c=0,f=1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='r')
				a=1;
			if(s[i]=='g')
				b=1;
			if(s[i]=='b')
				c=1;
			if((s[i]=='R'&&a==0)||(s[i]=='G'&&b==0)||(s[i]=='B'&&c==0)){
				f=0;
				break;
			}
		}
		puts(f==0? "NO":"YES");
	}
	return 0;
}