#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

int main(){
//	IOS;
	int n;
	cin >> n;
	int x,y;
 	int mnx=INT_MAX,mny=INT_MAX,mxx=-1,mxy=-1;
 	vector<vector<int>> ox(51),oy(51);
	for(int i=0;i<4*n+1;i++){
		cin >> x >> y;
  		mxx= mxx>x ? mxx:x;
		mxy= mxy>y ? mxy:y;
		mnx= mnx<x ? mnx:x;
		mny= mny<y ? mny:y;
		ox[x].push_back(y);
		oy[y].push_back(x);
	}
	int tx=-1,ty=-1;
	if(ox[mnx].size()>=n && ox[mxx].size()>=n && oy[mny].size()>=n && oy[mxy].size()>=n){
		for(int i=mnx+1;i<mxx;i++){
			for(int f:ox[i]){
				if(f!=mny && f!=mxy){
					cout << i << ' ' << f << '\n';
					return 0;
				}
			}
		}
	}
	else if(ox[mnx].size()==1) cout << mnx << ' ' << ox[mnx][0] << '\n';
	else if(ox[mxx].size()==1) cout << mxx << ' ' << ox[mxx][0] << '\n';
	else if(oy[mny].size()==1) cout << oy[mny][0] << ' ' << mny << '\n';
	else if(oy[mxy].size()==1) cout << oy[mxy][0] << ' ' << mxy << '\n';
	return 0;
}