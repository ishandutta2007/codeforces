// Author : WangZhikun
// Date   : 2018.09.16

#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}x*=f;
}
ll n,h;
pair<ll,ll> seg[200020];
int main(){
	read(n);read(h);
	for(int i=0;i<n;i++){
		read(seg[i].first);read(seg[i].second);
	}
	ll rem = h,end = 0,ans = 0,glid = seg[0].second-seg[0].first;
	for(int i=0;i<n;i++){
		if(i){
			glid-=seg[i-1].second-seg[i-1].first;
			if(end>=i){
				rem+=seg[i].first-seg[i-1].second;
			}else{
				rem = h;
				end = i;
				glid = seg[i].second-seg[i].first;
			}
		}
		while(end+1<n && rem-(seg[end+1].first-seg[end].second)>0){
			rem-=(seg[end+1].first-seg[end].second);
			glid+=seg[end+1].second-seg[end+1].first;
			end+=1;
			
		}
		//cout<<i<<' '<<end<<' '<<glid<<endl;
		ans = max(ans,glid+h);
	}
	cout<<ans<<endl;
	return 0;
}