#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN=3e5+5;
long long cnt[30], p[30], psa[MN][30], i, j;
string s;
inline int fnd(int x,int y){
	int ret = 0;
	for(int k=0;k<26;k++){
		if((!x)&&psa[y][k]>0) ret++;
		else if(x&&psa[y][k]-psa[x-1][k]>0) ret++;
	}
	return ret;
}

int main(){
	cin >> s; 
	for(i=1;i<=s.size();i++){
		for(j=0;j<26;j++)psa[i][j]=psa[i-1][j];
		psa[i][s[i-1]-'a']++;
		for(j=1;j<=26;j++){
			while(p[j]<i&&fnd(p[j]+1,i)>j) p[j]++;
			if(j==1) cnt[j]+=i-p[j];
			else cnt[j]+=p[j-1]-p[j];
		}
	}
	int mx = 0;
	for(i=0;i<26;i++)
		if(psa[s.size()][i]) mx++;
	printf("%d\n",mx);
	for(i=1;i<=mx;i++) printf("%lld\n",cnt[i]);
	return 0;
}