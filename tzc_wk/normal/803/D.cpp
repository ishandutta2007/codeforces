#include<bits/stdc++.h>
using namespace std;
int k;
char s[1000001];
int a[1000001],cnt=0;
bool check(int x){
	int len=0,ans=1;
	for(int i=1;i<=cnt;i++){
		if(a[i]-a[i-1]>x)	return 0;
		if(len+(a[i]-a[i-1])<=x)	len+=(a[i]-a[i-1]);
		else{
			ans++;
			len=a[i]-a[i-1];
		}
	}
	return (ans<=k);
}
int main(){
	cin>>k;
	getchar();
	int i=0;
	while(1){
		char ch=getchar();
		if(ch=='\n') break;
		s[i++]=ch;
	}
	int len=i;
	for(int i=0;i<len;i++)	if(s[i]==' '||s[i]=='-')	a[++cnt]=i+1;
    a[++cnt]=len;
    int l=0,r=len,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))	ans=mid,r=mid-1;
		else			l=mid+1;
	}
	cout<<ans<<endl;
}