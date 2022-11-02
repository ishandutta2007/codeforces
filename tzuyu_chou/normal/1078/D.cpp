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

int n;
int a[300001];
int l[18][300001],r[18][300001];
int mini[18][1048576],maxi[18][1048576];
bool out;
inline void build(int t,int id,int cl,int cr){
	if(cl==cr){
		mini[t][id]=l[t][cl];
		maxi[t][id]=r[t][cr];
		return;
	}
	int mid=(cl+cr)/2;
	build(t,id*2,cl,mid);
	build(t,id*2+1,mid+1,cr);
	mini[t][id]=min(mini[t][id*2],mini[t][id*2+1]);
	maxi[t][id]=max(maxi[t][id*2],maxi[t][id*2+1]);
}
inline int qmin(int t,int id,int cl,int cr,int ql,int qr){
	if(cl>qr || ql>cr) return 1e9;
	if(ql<=cl && cr<=qr) return mini[t][id];
	int mid=(cl+cr)/2;
	return min(qmin(t,id*2,cl,mid,ql,qr),qmin(t,id*2+1,mid+1,cr,ql,qr));
}
inline int qmax(int t,int id,int cl,int cr,int ql,int qr){
	if(cl>qr || ql>cr) return 0;
	if(ql<=cl && cr<=qr) return maxi[t][id];
	int mid=(cl+cr)/2;
	return max(qmax(t,id*2,cl,mid,ql,qr),qmax(t,id*2+1,mid+1,cr,ql,qr));
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	if(n==1){
		cout << 0 << endl;
		return 0;
	}
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=3*n ;i++){
		int cur=(i-1)%n+1;
		l[0][i]=max(1,i-a[cur]);
		r[0][i]=min(3*n,i+a[cur]);
	}
	for(int j=1; j<=17 ;j++){
		build(j-1,1,1,3*n);
		for(int i=1; i<=3*n ;i++){
			l[j][i]=max(1,qmin(j-1,1,1,3*n,l[j-1][i],r[j-1][i]));
			r[j][i]=min(3*n,qmax(j-1,1,1,3*n,l[j-1][i],r[j-1][i]));
		}
	}
	for(int i=1; i<=n ;i++){
		int cl=i+n,cr=i+n,ans=0;
		for(int j=16; j>=0 ;j--){
			int nl=max(1,qmin(j,1,1,3*n,cl,cr));
			int nr=min(3*n,qmax(j,1,1,3*n,cl,cr));
			if(nr-nl<n-1){
				ans|=(1<<j);
				cl=nl;
				cr=nr;
			}
		}
		cout << ans+1 << ' ';
	}
	cout << endl;
}