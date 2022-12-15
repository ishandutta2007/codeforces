#include <bits/stdc++.h>
using namespace std;

vector<int> v;
long long s, cnt, Q, x, y, i;

int main(){
	for(scanf("%lld",&Q);Q>0;Q--){
		scanf("%lld",&x);
		if(x==1){
			scanf("%lld",&y);
			if(v.size()){s-=v.back(); cnt--;}
			v.push_back(y); s+=y; cnt++;
			for(;v[i]<s/(double)cnt;i++)
				s += v[i], cnt++;
		}
		else printf("%.10lf\n",v.back()-s/(double)cnt);
	}
	return 0;
}