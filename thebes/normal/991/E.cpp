#include <bits/stdc++.h>
using namespace std;

long long f[22]={1}, cnt[21], ans;
string idk;

void calc(){
	int sz = 0;
	for(int j=0;j<=9;j++) sz+=cnt[j];
		for(int j=1;j<=9;j++){
			if(cnt[j]>=1){
				cnt[j]--;
				long long tot=f[sz-1];
				for(int k=0;k<=9;k++)
					tot/=f[cnt[k]];
				ans += tot;
				cnt[j]++;
			}
		}
}

void rec(int n){
	if(n==10) calc();
	else{
		int tmp = cnt[n]; rec(n+1);
		for(int i=0;i<tmp-1;i++)
			cnt[n]--,rec(n+1);
		cnt[n] = tmp;
	}
}

int main(){
	cin >> idk;
	for(char c : idk)
		cnt[c-'0']++;
	for(int i=1;i<=18;i++) f[i]=f[i-1]*i;
	rec(0);
	printf("%lld\n",ans);
	getchar(); getchar();
}