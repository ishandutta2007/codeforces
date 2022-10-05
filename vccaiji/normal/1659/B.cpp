#include<bits/stdc++.h>
using namespace std;
int n,k;
char s[210000];
char t[210000];
int f[210000];
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n>>k;
		scanf("%s",s+1);
		int l=k;
		for(int i=1;i<n;i++){
			if((s[i]-'0')^(k&1))f[i]=0;
			else{
				if(l){
				    f[i]=1;
					l--;	
				}
				else f[i]=0;
			}
		}
		f[n]=l;
		for(int i=1;i<=n;i++)cout<<(char)(((s[i]-'0')^((k-f[i])&1))+'0');
		cout<<endl;
		for(int i=1;i<=n;i++)cout<<f[i]<<" ";
		cout<<endl;
	}
	return 0;
}