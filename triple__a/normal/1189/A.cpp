#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;
char s[maxn];
int main(){
	int n;
	scanf("%d",&n);
	cin>>s;
	if (n%2==1){
		cout<<1<<endl;
		cout<<s;
	}
	else{
		int u=0;
		for (int i=0;i<n;++i){
			if (s[i]=='0'){
				++u;
			}
			else{
				--u;
			}
		}
		if (u){
			cout<<1<<endl;
			cout<<s<<endl;
		}
		else{
			cout<<2<<endl;
			cout<<s[0]<<" ";
			for (int i=1;i<n;++i){
				cout<<s[i];
			}
		}
	}
	return 0;
}