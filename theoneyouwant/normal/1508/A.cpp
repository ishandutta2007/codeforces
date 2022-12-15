//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fastio;

	int tests;
	cin>>tests;

	while(tests--){

		int n; cin>>n;
		string s1, s2, s3;
		cin>>s1>>s2>>s3;
		string ans;
		int ptr1 = 0, ptr2 = 0, ptr3 = 0;
		forn(i,3*n){
			int val[2] = {0};

			int tk = -1;
			int mx = -1;

			if((ptr1 == 2*n) || (ptr2 == 2*n) || (ptr3 == 2*n)){
				
				// cout << "index " << i+1 << endl;
				// cout << ptr1 << " " << ptr2 << " " << ptr3 << endl;
				// cout << s3[ptr3] - '0' << endl;

				if(ptr1 < 2*n){
					mx = max(mx, ptr1);
					tk = s1[ptr1] - '0';
				}
				if(ptr2 < 2*n){
					if(ptr2 > mx){
						mx = ptr2;
						tk = s2[ptr2] - '0';
					}
				}
				if(ptr3 < 2*n){
					if(ptr3 > mx){
						mx = ptr3;
						tk = s3[ptr3] - '0';
					}
				}				

				// cout << "max " << mx << endl;
			}

			if(ptr1 < 2*n){
				int c = s1[ptr1] - '0';
				val[c]++;
			}
			if(ptr2 < 2*n){
				int c = s2[ptr2] - '0';
				val[c]++;
			}
			if(ptr3 < 2*n){
				int c = s3[ptr3] - '0';
				val[c]++;
			}
			if((tk == 0) || (tk == -1 && val[0] >= val[1])){
				ans += '0';
				char sel = '0';
				if(ptr1 < 2*n){
					if(s1[ptr1] == sel) ptr1++; 
				}
				if(ptr2 < 2*n){
					if(s2[ptr2] == sel) ptr2++; 
				}
				if(ptr3 < 2*n){
					if(s3[ptr3] == sel) ptr3++; 
				}
			}
			else{
				ans += '1';
				char sel = '1';
				if(ptr1 < 2*n){
					if(s1[ptr1] == sel) ptr1++; 
				}
				if(ptr2 < 2*n){
					if(s2[ptr2] == sel) ptr2++; 
				}
				if(ptr3 < 2*n){
					if(s3[ptr3] == sel) ptr3++; 
				}
			}
		}

		int num = 0;
		if(ptr1 == 2*n) num++;
		if(ptr2 == 2*n) num++;
		if(ptr3 == 2*n) num++;

		// cout << ptr1 << " " << ptr2 << " " << ptr3 << endl;

		if(num < 2){
			// cout << s1 << " " << s2 << " " << s3 << endl;
			assert(num >= 2);
		}

		cout << ans << ln;
	}

	return 0;
}