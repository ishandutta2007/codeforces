#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int f(int l,int r){
	int cnt0=0,cnt1=0;
	for(int i=l;i<=r;i++){
		if(s[i-1]=='0')
			cnt0++;
		else cnt1++;
	}
	return cnt0==cnt1? 0:min(cnt0,cnt1);
}
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>s,n=s.size();
		if(f(1,n)==0)
			printf("%d\n",max(f(1,n-1),f(2,n)));
		else printf("%d\n",f(1,n));
	}
	return 0;
}