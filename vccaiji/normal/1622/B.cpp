#include<bits/stdc++.h>
using namespace std;
int a[210000];
char s[210000];
int q[210000];
int b[210000];
int main(){
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)b[a[i]]=i;
		scanf("%s",s+1);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1')cnt++;
		}
		int cnt1=n,cnt2=n-cnt;
		for(int i=n;i>=1;i--){
			if(s[b[i]]=='1'){
				q[b[i]]=cnt1;
				cnt1--;
			}
			else{
				q[b[i]]=cnt2;
				cnt2--;
			}
		}
		for(int i=1;i<=n;i++)cout<<q[i]<<' ';
		cout<<endl;
	}
	return 0;
}