/*
 Author	: 19362025
 Date	: 10/01/2020
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n,a[1000010];

ll ans = 0;

vector<int> md[100];
int V[1000010];
int main() {
	int c = clock();
	ios::sync_with_stdio(false);
	cin>>n;
	int cc;
	vector<int> K;
	for(int i=0;i<n;i++){
		cin>>cc;
		K.push_back(cc);
	}
	sort(K.begin(),K.end());
	for(int i=0;i<K.size();i++) if(K[i] == K[i+1])ans = max(ans,1ll*K[i]);
	K.erase(unique(K.begin(),K.end()),K.end());
	for(int i=0;i<K.size();i++) for(int j=1;j<30;j++) if((K[i]%j) != 0) md[j].push_back(K[i]), V[i] = K[i];
	
	for(int i=K.size()-1;i;i--){
		int j = i-1;
		if(1.0*(clock()-c)/CLOCKS_PER_SEC>0.9)break;
		while(j>=0){
			//cout<<i<<' '<<j<<' '<<V[i]<<' '<<V[j]<<endl;
			if(1ll*V[i]*V[j]<=ans)break;
			int cg = __gcd(V[i],V[j]);
			ans = max(ans,1ll*V[i]*V[j]/cg);
			if(cg<30){
				vector<int>::iterator it = lower_bound(md[cg].begin(),md[cg].end(),V[j]);
				if(it == md[cg].begin())break;
				it--;
				j = lower_bound(K.begin(),K.end(),*it)-K.begin();
			}else j--;
		}
	}
	cout<<ans<<endl;
	return 0;
}