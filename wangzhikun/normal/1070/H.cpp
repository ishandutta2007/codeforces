// Author : WangZhikun
// Date   : 2018-10-18
// ????????????????

#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int n,m,q;
char cu[10010][10],qu[100];
map<ll,int> nms,cid;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int id=1;id<=n;id++){
		cin>>cu[id];
		m = strlen(cu[id]);
		for(int i=0;i<m;i++){
			ll hsh = 0;
			
			for(int j=i;j<m;j++){
				hsh = hsh*128+cu[id][j];
				if(cid[hsh]!=id){
					nms[hsh]++;
					cid[hsh] = id;
				}
				
			}
			
		}
	}
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>qu;
		m = strlen(qu);
		ll hsh = 0;
		for(int j=0;j<m;j++){
			hsh = hsh*128+qu[j];
		}
		cout<<nms[hsh]<<' ';
		if(nms[hsh]){
			cout<<cu[cid[hsh]]<<'\n';
		}else{
			cout<<"-\n";
		}
	}
	return 0;
}