#include <bits/stdc++.h>
using namespace std;

const int MN = 1e6+5;
int p[MN][2], N, i, ans, x, o[MN];
string s; queue<int> d;

int main(){
	cin >> s; N = s.size();
	for(i=0;i<N;i++) p[i][0]=i-1,p[i][1]=i+1;
	for(i=0;i<N-1;i++){
		if(s[i]!=s[i+1]){
			if(!o[i]){d.push(i); o[i]=1;}
			if(!o[i+1]){d.push(i+1);o[i+1]=1;}
		}
	}
	while(!d.empty()){
		int sz = d.size();
		while(sz--){
			int x = d.front(); d.pop();
			int l = p[x][0], r = p[x][1];
			p[l][1] = r; p[r][0] = l;
			d.push(x);
		}
		sz = d.size();
		while(sz--){
			x = d.front(); d.pop();
			if(p[p[x][0]][1] != p[x][1]) continue;
			int l = p[x][0], r = p[x][1];
			if(l>=0 && r < N && s[r] != s[l]){
				if(!o[l]){d.push(l); o[l]=1;}
				if(!o[r]){d.push(r); o[r]=1;}
			}
		}
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}