//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();

    const int alphabet = 150;

    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> kasai(string txt, vector<int> suffixArr) 
{ 
    int n = suffixArr.size(); 
  
    // To store LCP array 
    vector<int> lcp(n, 0); 
  
    // An auxiliary array to store inverse of suffix array 
    // elements. For example if suffixArr[0] is 5, the 
    // invSuff[5] would store 0.  This is used to get next 
    // suffix string from suffix array. 
    vector<int> invSuff(n, 0); 
  
    // Fill values in invSuff[] 
    for (int i=0; i < n; i++) 
        invSuff[suffixArr[i]] = i; 
  
    // Initialize length of previous LCP 
    int k = 0; 
  
    // Process all suffixes one by one starting from 
    // first suffix in txt[] 
    for (int i=0; i<n; i++) 
    { 
        /* If the current suffix is at n-1, then we dont 
           have next substring to consider. So lcp is not 
           defined for this substring, we put zero. */
        if (invSuff[i] == n-1) 
        { 
            k = 0; 
            continue; 
        } 
  
        /* j contains index of the next substring to 
           be considered  to compare with the present 
           substring, i.e., next string in suffix array */
        int j = suffixArr[invSuff[i]+1]; 
  
        // Directly start matching from k'th index as 
        // at-least k-1 characters will match 
        while (i+k<n && j+k<n && txt[i+k]==txt[j+k]) 
            k++; 
  
        lcp[invSuff[i]] = k; // lcp for the present suffix. 
  
        // Deleting the starting character from the string. 
        if (k>0) 
            k--; 
    } 
  
    // return the constructed lcp array 
    return lcp; 
} 

v32 suffix_array_construction(string ch) {
	v32 sorted_shifts = sort_cyclic_shifts(ch);
	return sorted_shifts;
}

int link[LIM] = {0};
ll sz[LIM] = {0};
ll num[LIM] = {0};

int find(int x){
	if(x == link[x]) return x;
	return (link[x] = find(link[x]));
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	if(sz[a]<sz[b]) swap(a,b);
	sz[a]+=sz[b];
	link[b] = a;
	num[a] += num[b];
}

int main(){
	fastio;

	int n; cin>>n;
	string s; cin>>s;
	string t; cin>>t;

	ll mx = 0;
	forn(i,t.length()){
		if(t[i] == '0') mx = max(mx, (ll)i+1);
	}

	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());

	s += '$';
	v32 sorted_shifts = suffix_array_construction(s);
	v32 lcp = kasai(s, sorted_shifts);
	// cout<<"OK"<<endl;
	
	sorted_shifts.erase(sorted_shifts.begin());
	lcp.erase(lcp.begin());

	// cout<<sorted_shifts<<ln;

	forn(i,sorted_shifts.size()){
		int ind = sorted_shifts[i];
		if(t[ind] == '0') num[i] = 1;
		else num[i] = 0;
	}

	forn(i,LIM){
		sz[i] = 1;
		link[i] = i;
	}

	priority_queue<pair<int,int>> q;
	forn(i,n) q.push(mp(lcp[i], i));

	ll mxsz = 0;

	rforsn(i,n,1){
		while(!q.empty() && q.top().fi >= i){
			auto t = q.top();
			q.pop();
			if(t.se == sorted_shifts.size()-1) continue;
			unite(t.se, t.se+1);
			mxsz = max(mxsz, num[find(t.se)]);
		}
		mx = max(mx, mxsz * i);
	}

	cout<<mx<<ln;

	return 0;
}