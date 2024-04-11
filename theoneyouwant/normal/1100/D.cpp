//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define leadzero(a) __builtin_clz(a) // count leading zeroes
#define trailzero(a) __builtin_ctz(a) // count trailing zeroes
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
#define ln endl
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl;
#define dbgstl32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it<<ln;} cerr<<endl
#define dbgstlp32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it.fi<<" , "<<it.se<<ln;} cerr<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inp freopen("input.txt", "r", stdin)
#define outp freopen("output.txt", "w", stdout)
#define dbgm(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
typedef long long int  ll;
typedef long double  ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM = 1002, MOD = 1e9+7, EPS = 1e-9;
int t,n,m,k,x,y;
int main(){
	fastio;
	bool placed[LIM][LIM];
	forn(i,LIM){
		forn(j,LIM){
			placed[i][j] = 0;
		}
	}
	vector<p32> v;
	v.pb(mp(0,0));
	int kx,ky;
	cin>>kx>>ky;
	forn(i,666){
		cin>>x>>y;
		placed[x][y] = 1;
		v.pb(mp(x,y));
	}
	//bool done=0;
	int r1,r2,r3;
	//int done=0;

	while(kx!=500 || ky!=500){
			if(kx>500 && ky>500){
				if(placed[kx-1][ky-1]==1){
					kx-=1;
				}
				else{
					kx-=1;
					ky-=1;
				}
			}
			else if(kx>500 && ky<500){
				if(placed[kx-1][ky+1]==1){
					kx-=1;
				}
				else{
					kx-=1;
					ky+=1;
				}
			}
			else if(kx<500 && ky<500){
				if(placed[kx+1][ky+1]==1){
					kx+=1;
				}
				else{
					kx+=1;
					ky+=1;
				}
			}
			else if(kx<500 && ky>500){
				if(placed[kx+1][ky-1]==1){
					kx+=1;
				}
				else{
					kx+=1;
					ky-=1;
				}
			}
			else if(kx==500 && ky<500){
				ky+=1;
			}
			else if(kx==500 && ky>500){
				ky-=1;
			}
			else if(ky==500 && kx>500){
				kx-=1;
			}
			else if(ky==500 && kx<500){
				kx+=1;
			}
		cout<<kx<<" "<<ky<<endl;
		cin>>r1>>r2>>r3;
		if(r1<=0) return 0;
		//else if(r1==0 && r2==0 && r3==0) return 0;
		else{
			p32 t = v[r1];
			placed[t.fi][t.se]=0;
			v[r1] = mp(r2,r3);
			placed[r2][r3]=1;
		}
	}

	while(true){
		if(kx==500){
			int t1=0,t2=0,t3=0,t4=0;
			forsn(i,1,501){
				forsn(j,1,501){
					t1+=(int)placed[i][j];
				}
			}
			forsn(i,501,1000){
				forsn(j,501,1000){
					t2+=(int)placed[i][j];
				}
			}
			forsn(i,501,1000){
				forsn(j,1,501){
					t3+=(int)placed[i][j];
				}
			}
			forsn(i,1,501){
				forsn(j,501,1000){
					t4+=(int)placed[i][j];
				}
			}
			if(t2 == min({t1,t2,t3,t4})){
				if(placed[kx-1][ky-1]==1){
					kx-=1;
				}
				else{
					kx-=1;
					ky-=1;
				}
			}
			else if(t1 == min({t1,t2,t3,t4})){
				if(placed[kx+1][ky+1]==1){
					kx+=1;
				}
				else{
					kx+=1;
					ky+=1;
				}
			}
			else if(t4 == min({t1,t2,t3,t4})){
				if(placed[kx+1][ky-1]==1){
					kx+=1;
				}
				else{
					kx+=1;
					ky-=1;
				}
			}
			else{
				if(placed[kx-1][ky+1]==1){
					kx-=1;
				}
				else{
					kx-=1;
					ky+=1;
				}
			}
		}
		else if(kx>500 && ky>500){
			if(placed[kx+1][ky+1]==1){
				kx+=1;
			}
			else{
				kx+=1;
				ky+=1;
			}
		}
		else if(kx<500 && ky<500){
			if(placed[kx-1][ky-1]==1){
				kx-=1;
			}
			else{
				kx-=1;
				ky-=1;
			}
		}
		else if(kx>500 && ky<500){
			if(placed[kx+1][ky-1]==1){
				kx+=1;
			}
			else{
				kx+=1;
				ky-=1;
			}
		}
		else if(kx<500 && ky>500){
			if(placed[kx-1][ky+1]==1){
				kx-=1;
			}
			else{
				kx-=1;
				ky+=1;
			}
		}
		cout<<min(max(1,kx),999)<<" "<<min(max(1,ky),999)<<endl;
		cin>>r1>>r2>>r3;
		if(r1<=0) return 0;
		//else if(r1==0 && r2==0 && r3==0) return 0;
		else{
			p32 t = v[r1];
			placed[t.fi][t.se]=0;
			v[r1] = mp(r2,r3);
			placed[r2][r3]=1;
		}
	}
	return 0;
}