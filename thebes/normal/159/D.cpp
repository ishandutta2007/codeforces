#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 2002;
ll cnt[MN], hsh[MN], rhsh[MN], p[MN]={1}, N, i, j, ans;
ll getHsh(ll x,ll w){return hsh[x+w]-hsh[x-1]*p[w+1];}
ll getRhsh(ll x,ll w){return rhsh[x-w]-rhsh[x+1]*p[w+1];}
string s;

int main(){
	cin >> s; N = s.size(); s.insert(0," ");
	for(i=1;i<=N;i++){
		hsh[i] = (hsh[i-1]*33+s[i]-'a');
		p[i] = (p[i-1]*33);
	}
	for(i=N;i>=1;i--){
		rhsh[i] = (rhsh[i+1]*33+s[i]-'a');
		cnt[i] = cnt[i+1];
		for(j=i;j<=N;j++){
			if(getHsh(i,j-i)==getRhsh(j,j-i)){
				cnt[i]++; ans += cnt[j+1];
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}