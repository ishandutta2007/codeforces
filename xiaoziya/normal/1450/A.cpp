#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		cin>>s;
		sort(s.begin(),s.end());
		cout<<s<<"\n";
	}
	return 0;
}