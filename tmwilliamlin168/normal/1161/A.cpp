#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	int x[k], c1[n]={}, c2[n]={}, d1[k+1]={};
	ll ans=0;
	for(int i=0; i<k; ++i) {
		cin >> x[i], --x[i];
		//d1[i+1]=d1[i];
		//if(!c1[x[i]])
			//++d1[i+1];
		//++c1[x[i]];
		//cout << i+1 << " " << d1[i+1] << endl;
	}
	for(int i=0; i<k; ++i) {
		c2[x[i]]=i+1;
	}
	//for(int i=0; i<n; ++i)
		//ans+=(ll)(n-d1[c2[i]]);//, cout << i << " " << c2[i] << " " << d1[c2[i]] << endl;
	for(int i=0; i<k; ++i) {
		++c1[x[i]];
		if(i+1<c2[x[i]])
			continue;
		ans+=(x[i]>0&&!c1[x[i]-1])+(x[i]<n-1&&!c1[x[i]+1]);
	}
	for(int i=0; i<n; ++i)
		if(!c1[i])
			ans+=1+(i>0)+(i<n-1);
	cout << ans;
}