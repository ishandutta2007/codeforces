#include <bits/stdc++.h>
using namespace std;

const int N=200050;
int n,q,pref[N][2];
char s[N];
int main(){
	scanf("%i%i",&n,&q);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++){
			pref[i][j]=pref[i-1][j];
			if(s[i]==(char)('0'+j)&&s[i+1]==s[i])pref[i][j]++;
		}
	}
	while(q--){
		int l,r;scanf("%i%i",&l,&r);
		r--;
		printf("%i\n",max(pref[r][0]-pref[l-1][0],pref[r][1]-pref[l-1][1])+1);
	}
	return 0;
}