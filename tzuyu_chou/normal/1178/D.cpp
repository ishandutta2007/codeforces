/*
          _______             _______  _        ______     _______  _______ 
|\     /|(  ___  )|\     /|  (  ___  )( (    /|(  __  \   (       )(  ____ \
( \   / )| (   ) || )   ( |  | (   ) ||  \  ( || (  \  )  | () () || (    \/
 \ (_) / | |   | || |   | |  | (___) ||   \ | || |   ) |  | || || || (__    
  \   /  | |   | || |   | |  |  ___  || (\ \) || |   | |  | |(_)| ||  __)   
   ) (   | |   | || |   | |  | (   ) || | \   || |   ) |  | |   | || (      
   | |   | (___) || (___) |  | )   ( || )  \  || (__/  )  | )   ( || (____/\
   \_/   (_______)(_______)  |/     \||/    )_)(______/   |/     \|(_______/
   
_________ _         _________          _______ 
\__   __/( (    /|  \__   __/|\     /|(  ____ \
   ) (   |  \  ( |     ) (   | )   ( || (    \/
   | |   |   \ | |     | |   | (___) || (__    
   | |   | (\ \) |     | |   |  ___  ||  __)   
   | |   | | \   |     | |   | (   ) || (      
___) (___| )  \  |     | |   | )   ( || (____/\
\_______/|/    )_)     )_(   |/     \|(_______/
                                               
 _______  _______  _______  _        _       _________ _______          _________
(       )(  ___  )(  ___  )( (    /|( \      \__   __/(  ____ \|\     /|\__   __/
| () () || (   ) || (   ) ||  \  ( || (         ) (   | (    \/| )   ( |   ) (   
| || || || |   | || |   | ||   \ | || |         | |   | |      | (___) |   | |   
| |(_)| || |   | || |   | || (\ \) || |         | |   | | ____ |  ___  |   | |   
| |   | || |   | || |   | || | \   || |         | |   | | \_  )| (   ) |   | |   
| )   ( || (___) || (___) || )  \  || (____/\___) (___| (___) || )   ( |   | |   
|/     \|(_______)(_______)|/    )_)(_______/\_______/(_______)|/     \|   )_(   
 
https://www youtube com/watch?v=Fm5iP0S1z9w
*/
 
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod7=1000000007LL;
inline ll getint() {
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add(ll _x, ll _y, ll _mod=mod7) {
  _x+=_y;
  return _x>=_mod ? _x-_mod : _x;
}
inline ll sub(ll _x, ll _y, ll _mod=mod7) {
  _x-=_y;
  return _x<0 ? _x+_mod : _x;
}
inline ll mul(ll _x, ll _y ,ll _mod=mod7) {
  _x*=_y;
  return _x>=_mod ? _x%_mod : _x;
}
ll mypow(ll _a, ll _x, ll _mod) {
  if(_x == 0) return 1ll;
  ll _ret = mypow(mul(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=mul(_ret, _a, _mod);
  return _ret;
}
ll mymul(ll _a, ll _x, ll _mod) {
  if(_x == 0) return 0ll;
  ll _ret = mymul(add(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=add(_ret, _a, _mod);
  return _ret;
}
void sleep(double sec = 1021) {
	clock_t s = clock();
	while(clock() - s < CLOCKS_PER_SEC * sec);
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/

const int mxN=2e3;
bool c[mxN+1];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	
	for(int i=2; i<=mxN; ++i) {
		if(c[i])
			continue;
		for(int j=i*i; j<=mxN; j+=i)
			c[j]=1;
	}
	/*
	for(int i=4; i<=mxN/2; ++i) {
		bool ok=0;
		for(int j=i; j<=i+i/2; ++j)
			ok|=!c[j];
		if(!ok)
			cout << i << endl;
	}
	*/
	int n;
	cin >> n;
	vector<array<int, 2>> ans;
	for(int i=0; i<n; ++i) {
		ans.push_back({i, (i+1)%n});
	}
	int i=0;
	while(c[ans.size()]) {
		ans.push_back({i, i+n/2});
		i++;
	}
	cout << ans.size() << endl;
	for(array<int, 2> a:ans)
		cout << a[0]+1 << " " << a[1]+1 << endl;
}