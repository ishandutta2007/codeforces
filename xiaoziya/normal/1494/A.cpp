#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>s,n=s.size(),flg=0;
		for(int a=-1;a<=1;a+=2)
			for(int b=-1;b<=1;b+=2)
				for(int c=-1;c<=1;c+=2){
					int sum=0,f=1;
					for(int i=0;i<n;i++)
						sum+=s[i]=='A'? a:(s[i]=='B'? b:c),f&=(sum>=0);
					f&=(sum==0);
					if(f){
						flg=1;
						break;
					}
				}
		puts(flg==0? "NO":"YES");
	}
	return 0;
}