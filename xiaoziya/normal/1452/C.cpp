#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>s,ans=0,n=s.size();
		int a=0,b=0;
		for(int i=0;i<n;i++){
			if(s[i]=='(')
				a++;
			if(s[i]=='[')
				b++;
			if(s[i]==')')
				if(a)
					a--,ans++;
			if(s[i]==']')
				if(b)
					b--,ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}