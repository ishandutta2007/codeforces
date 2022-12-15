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
const int LIM = 2e5+5, MOD = 1e9+7, EPS = 1e-9;
int t,n,m,k,x,y;

void z_func(string &s, v32 &z){
	int L=0;
	int R=0;
	int sz = s.size();
	z.assign(sz,0);
	forsn(i,1,sz){
		if(i>R){
			L = R = i;
			while(R<sz && s[R-L] == s[R]) R++;
			z[i] = R-L; R--;
		}
		else{
			int k = i-L;
			if(z[k]<R-i+1) z[i] = z[k];
			else{
				L = i;
				while(R<sz && s[R-L]==s[R]) R++;
				z[i] = R-L;
				R--;
			}
		}
	}
}

int main(){
	fastio;
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	if(s1.find(s2)!=string::npos){
		s2 = s1[0];
	}
	if(s1.find(s3)!=string::npos){
		s3=s1[0];
	}
	if(s2.find(s1)!=string::npos){
		s1 = s2[0];
	}
	if(s2.find(s3)!=string::npos){
		s3=s2[0];
	}
	if(s3.find(s2)!=string::npos){
		s2 = s3[0];
	}
	if(s3.find(s1)!=string::npos){
		s1=s3[0];
	}
	 string str[3];
	str[0] = s1;
	str[1] = s2;
	str[2] = s3;
	//cout<<"OK"<<ln;
	ll ans = 1e9;
	int myints[] = {1,2,3};
	string sk;
		sk = str[myints[1]-1];
		sk.append(str[myints[0]-1]);
		//cout<<sk<<endl;
		v32 z;
		z_func(sk, z);
		int y;
		int rg = str[myints[0]-1].size();
		while(rg<sk.size() && rg+z[rg]<sk.size()) rg++;
		if(rg==sk.size()) y=0;
		else y = min({(int)str[myints[1]-1].size(),z[rg],(int)str[myints[0]-1].size()});
		//cout<<y<<ln;
		sk = str[myints[0]-1];
		//cout<<sk<<ln;
		//cout<<y<<ln;
		if(y!= str[myints[1]-1].size())sk.append(str[myints[1]-1],y,str[myints[1]-1].size()-y);
		//cout<<sk<<ln;
		if(sk.find(str[myints[2]-1])!=string::npos){
			ans = min(ans,(ll)sk.size());
		}
		s2 = str[myints[2]-1];
		s2.append(sk);
	//	cout<<s2<<ln;
		z.clear();
		z_func(s2,z);
		rg = str[myints[2]-1].size();
		while(rg<s2.size() && rg+z[rg]<s2.size()) rg++;
		if(rg==s2.size()) y=0;
		else y = min({(int)str[myints[2]-1].size(),z[rg],(int)sk.size()});
	//	y = z[s2.size()];
	//	cout<<y<<ln;
		s2 = sk;
	//	cout<<s2<<ln;
		if(y!= str[myints[2]-1].size())s2.append(str[myints[2]-1],y,str[myints[2]-1].size()-y);
	//	cout<<s2<<ln;
	//	cout<<s2<<ln;
		ans = min(ans,(ll)s2.size());
	//	cout<<ans<<endl;
	while(next_permutation(myints,myints+3)){
		sk = str[myints[1]-1];
		// forn(i,3){
		// 	cout<<myints[i]<<" ";
		// }
		//cout<<endl;
		sk.append(str[myints[0]-1]);
		//cout<<sk<<endl;
		z.clear();
		z_func(sk, z);
		rg = str[myints[0]-1].size();
		while(rg<sk.size() && rg+z[rg]<sk.size()) rg++;
		if(rg==sk.size()) y=0;
		else y = min({(int)str[myints[1]-1].size(),z[rg],(int)str[myints[0]-1].size()});
		//cout<<y<<ln;
	//	cout<<sk<<" "<<y<<" ";
		sk = str[myints[0]-1];
		if(y!= str[myints[1]-1].size())sk.append(str[myints[1]-1],y,str[myints[1]-1].size()-y);
		//cout<<sk<<ln;
		if(sk.find(str[myints[2]-1])!=string::npos){
			ans = min(ans,(ll)sk.size());
		}
	//		cout<<ans<<endl;
	//	cout<<sk<<ln;
	//	cout<<s2<<ln;
		s2 = str[myints[2]-1];
		s2.append(sk);
	//	cout<<s2<<" ";
		z.clear();
		z_func(s2,z);
		//cout<<ans<<endl;	
		rg = str[myints[2]-1].size();
		while(rg<s2.size() && rg+z[rg]<s2.size()) rg++;
		if(rg==s2.size()) y=0;
		else y = min({(int)str[myints[2]-1].size(),z[rg],(int)sk.size()});
	//	y = z[s2.size()];
	//	cout<<y<<ln;
		//cout<<ans<<endl;
		s2 = sk;
	//	cout<<s2<<endl;
	//	cout<<y<<endl;
		if(y!= str[myints[2]-1].size()) s2.append(str[myints[2]-1],y,str[myints[2]-1].size()-y);
	//	cout<<sk<<" "<<s2<<ln;
		ans = min(ans,(ll)s2.size());
	//	cout<<ans<<endl;
	}
	cout<<ans<<ln;

	return 0;
}