/*
_________            _______  _        _        _______    _        _        _______          
\__   __/  |\     /|(  ___  )( (    /|( (    /|(  ___  )  | \    /\( (    /|(  ___  )|\     /|
   ) (     | )   ( || (   ) ||  \  ( ||  \  ( || (   ) |  |  \  / /|  \  ( || (   ) || )   ( |
   | |     | | _ | || (___) ||   \ | ||   \ | || (___) |  |  (_/ / |   \ | || |   | || | _ | |
   | |     | |( )| ||  ___  || (\ \) || (\ \) ||  ___  |  |   _ (  | (\ \) || |   | || |( )| |
   | |     | || || || (   ) || | \   || | \   || (   ) |  |  ( \ \ | | \   || |   | || || || |
___) (___  | () () || )   ( || )  \  || )  \  || )   ( |  |  /  \ \| )  \  || (___) || () () |
\_______/  (_______)|/     \||/    )_)|/    )_)|/     \|  |_/    \/|/    )_)(_______)(_______)
                                                                                              
 _        _        _______             _        _        _______             _        _        _______          
| \    /\( (    /|(  ___  )|\     /|  | \    /\( (    /|(  ___  )|\     /|  | \    /\( (    /|(  ___  )|\     /|
|  \  / /|  \  ( || (   ) || )   ( |  |  \  / /|  \  ( || (   ) || )   ( |  |  \  / /|  \  ( || (   ) || )   ( |
|  (_/ / |   \ | || |   | || | _ | |  |  (_/ / |   \ | || |   | || | _ | |  |  (_/ / |   \ | || |   | || | _ | |
|   _ (  | (\ \) || |   | || |( )| |  |   _ (  | (\ \) || |   | || |( )| |  |   _ (  | (\ \) || |   | || |( )| |
|  ( \ \ | | \   || |   | || || || |  |  ( \ \ | | \   || |   | || || || |  |  ( \ \ | | \   || |   | || || || |
|  /  \ \| )  \  || (___) || () () |  |  /  \ \| )  \  || (___) || () () |  |  /  \ \| )  \  || (___) || () () |
|_/    \/|/    )_)(_______)(_______)  |_/    \/|/    )_)(_______)(_______)  |_/    \/|/    )_)(_______)(_______)
 
https://www youtube com/watch?v=i0p1bmr0EmE
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

int n,m;
string s;
string ans;
string tmp;
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
    int l=0,r=s.size()-1;
    while(r-l>=3){
        int c[3];
        c[0]=c[1]=c[2]=0;
        c[s[l]-'a']++;
        c[s[l+1]-'a']++;
        c[s[r-1]-'a']++;
        c[s[r]-'a']++;
        for(int j=0; j<3 ;j++){
            if(c[j]>=2){
                ans+=(char)('a'+j);
                break;
            }
        }
        l+=2;r-=2;
    }
    tmp=ans;
    reverse(tmp.begin(),tmp.end());
    if(r-l>=0){
        ans=ans+s[l]+tmp;
    }
    else{
        ans=ans+tmp;
    }
    cout << ans << endl;
}