/*
_________ _______    _       _________ _        _______   __________________
\__   __/(       )  ( \      \__   __/| \    /\(  ____ \  \__   __/\__   __/
   ) (   | () () |  | (         ) (   |  \  / /| (    \/     ) (      ) (   
   | |   | || || |  | |         | |   |  (_/ / | (__         | |      | |   
   | |   | |(_)| |  | |         | |   |   _ (  |  __)        | |      | |   
   | |   | |   | |  | |         | |   |  ( \ \ | (           | |      | |   
___) (___| )   ( |  | (____/\___) (___|  /  \ \| (____/\     | |      | |   
\_______/|/     \|  (_______/\_______/|_/    \/(_______/     )_(      )_(  
 
_________          _______ _________   _       _________ _        _______   __________________
\__    _/|\     /|(  ____ \\__   __/  ( \      \__   __/| \    /\(  ____ \  \__   __/\__   __/
   )  (  | )   ( || (    \/   ) (     | (         ) (   |  \  / /| (    \/     ) (      ) (   
   |  |  | |   | || (_____    | |     | |         | |   |  (_/ / | (__         | |      | |   
   |  |  | |   | |(_____  )   | |     | |         | |   |   _ (  |  __)        | |      | |   
   |  |  | |   | |      ) |   | |     | |         | |   |  ( \ \ | (           | |      | |   
|\_)  )  | (___) |/\____) |   | |     | (____/\___) (___|  /  \ \| (____/\     | |      | |   
(____/   (_______)\_______)   )_(     (_______/\_______/|_/    \/(_______/     )_(      )_(  
 
https://www youtube com/watch?v=ePpPVE-GGJw
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

typedef double dd;
dd a,b,c;
dd x1,x2,y1,y2;
dd ans;
dd p[2],q[2],r[2],s[2];
dd dis(dd sx,dd sy,dd ex,dd ey){
	return abs(ex-sx)+abs(ey-sy);
}
dd dis2(dd sx,dd sy,dd ex,dd ey){
	return sqrt((sx-ex)*(sx-ex)+(sy-ey)*(sy-ey));
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
	if(a==0 || b==0){
		cout << fixed << setprecision(10) << dis(x1,y1,x2,y2) << '\n';
		return 0;
	}
	p[0]=x1,p[1]=(b*y1+c)/-a;
	r[0]=(a*x1+c)/-b,r[1]=y1;
	q[0]=x2,q[1]=(b*y2+c)/-a;
	s[0]=(a*x2+c)/-b,s[1]=y2;
	ans=dis(x1,y1,x2,y2);
	ans=min(ans,dis(x1,y1,p[0],r[0])+dis(x2,y2,q[0],s[0])+dis2(p[0],r[0],q[0],s[0]));
	ans=min(ans,dis(x1,y1,p[0],r[0])+dis(x2,y2,q[1],s[1])+dis2(p[0],r[0],q[1],s[1]));
	ans=min(ans,dis(x1,y1,p[1],r[1])+dis(x2,y2,q[0],s[0])+dis2(p[1],r[1],q[0],s[0]));
	ans=min(ans,dis(x1,y1,p[1],r[1])+dis(x2,y2,q[1],s[1])+dis2(p[1],r[1],q[1],s[1]));
	cout << fixed << setprecision(10) << ans << '\n';
}