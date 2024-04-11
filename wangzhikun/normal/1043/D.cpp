//  Created by WangZhikun on 2018/10/28.

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,m,pl[12][120010],po[12][120010];
ll ans = 0;
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&pl[i][j]);
			po[i][pl[i][j]] = j;
		}
	}
	int cpo[12],cnt,ok;
	cpo[0] = 0;
	while(cpo[0]<n){
		cnt = 2;
		ok=1;
		for(register int i=1;i<m;i++)cpo[i] = po[i][pl[0][cpo[0]]];
		while(1){
			for(register int i=0;i<m;i++){
				++cpo[i];
				if(cpo[i]>=n || pl[0][cpo[0]] != pl[i][cpo[i]]){
					ok=0;break;
				}
			}
			if(!ok)break;
			++cnt;
		}
		ans+= 1ll*cnt*(cnt-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}