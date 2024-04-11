#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N=105;
int n,m;char s[N],ans[N];
int main(){
	scanf("%d\n%s",&n,s);
	for(int i=0;i<n;){
		if (s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o'){
			ans[m]=ans[m+1]=ans[m+2]='*',m+=3; i+=3; 
			while (s[i]=='g'&&s[i+1]=='o') i+=2;
		} else ans[m++]=s[i],i++;
	}
	puts(ans);
	return 0;
}