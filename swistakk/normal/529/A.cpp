#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, t) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#t <<" = " <<t<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x,y,z,t)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
using namespace std;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third; };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}

// lexicographic order for pairs
inline bool leq(int a1, int a2, int b1, int b2) {
    return(a1 < b1 || a1 == b1 && a2 <= b2);
}
 
// and triples
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
    return(a1 < b1 || a1 == b1 && leq(a2,a3, b2,b3));
} // and triples
 
// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
static void radixPass(int* a, int* b, int* r, int n, int K) {// count occurrences
    int* c = new int[K + 1]; // counter array
    for (int i = 0; i <= K; i++) c[i] = 0; // reset counters
    for (int i = 0; i < n; i++) c[r[a[i]]]++; // count occurrences
    for (int i = 0, sum = 0; i <= K; i++) // exclusive prefix sums
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (int i = 0;  i < n; i++) b[c[r[a[i]]]++] = a[i]; // sort
    delete [] c;
}
 
// find the suffix array SA of s[0..n-1] in {1..K}n
// require s[n]=s[n+1]=s[n+2]=0, n>=2
void suffixArray(int* s, int* SA, int n, int K) {
    int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0+n2;
    int* s12 = new int[n02+3]; s12[n02] = s12[n02+1] = s12[n02+2] = 0;
    int* SA12 = new int[n02+3]; SA12[n02] = SA12[n02+1] = SA12[n02+2] = 0;
    int* s0 = new int[n0];
    int* SA0 = new int[n0];
    // generate positions of mod 1 and mod 2 suffixes
    // the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
    for (int i=0, j=0; i < n + (n0-n1); i++)
        if (i%3 != 0) s12[j++] = i;
    // lsb radix sort the mod 1 and mod 2 triples
    radixPass(s12 , SA12, s+2, n02, K);
    radixPass(SA12, s12 , s+1, n02, K);
    radixPass(s12 , SA12, s  , n02, K);
    // find lexicographic names of triples
    int name = 0, c0 = -1, c1 = -1, c2 = -1;
    for (int i = 0; i < n02; i++) {
        if (s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2) {
            name++;
            c0 = s[SA12[i]];
            c1 = s[SA12[i]+1];
            c2 = s[SA12[i]+2];
        }
        if (SA12[i]%3 == 1) s12[SA12[i]/3] = name; // left half
        else s12[SA12[i]/3 + n0] = name; // right half
    }
    // recurse if names are not yet unique
    if (name < n02) {
        suffixArray(s12, SA12, n02, name);
        // store unique names in s12 using the suffix array
        for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
    } else // generate the suffix array of s12 directly
        for (int i = 0;  i < n02; i++) SA12[s12[i] - 1] = i;
    // stably sort the mod 0 suffixes from SA12 by their first character
    for (int i = 0, j = 0; i < n02; i++)
        if (SA12[i] < n0) s0[j++] = 3*SA12[i];
    radixPass(s0, SA0, s, n0, K);
    // merge sorted SA0 suffixes and sorted SA12 suffixes
    for (int p = 0, t = n0-n1, k = 0; k < n; k++) {
        #define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
        int i = GetI(); // pos of current offset 12 suffix
        int j = SA0[p]; // pos of current offset 0 suffix
        if (SA12[t] < n0 ? // different compares for mod 1 and mod 2 suffixes
            leq(s[i], s12[SA12[t] + n0], s[j], s12[j/3]) :
            leq(s[i],s[i+1],s12[SA12[t]-n0+1], s[j],s[j+1],s12[j/3+n0]))
        {// suffix from SA12 is smaller
            SA[k] = i; t++;
            if (t == n02) // done --- only SA0 suffixes left
            for (k++; p < n0; p++, k++) SA[k] = SA0[p];
        } else {// suffix from SA0 is smaller
            SA[k] = j; p++;
            if (p == n0) // done --- only SA12 suffixes left
            for (k++; t < n02; t++, k++) SA[k] = GetI();
        }
    }
    delete [] s12; delete [] SA12; delete [] SA0; delete [] s0;
}

const int N = 2e6 + 5;
int s[N];
int SA[N];
vector<int> MinK(vector<int> vec, int k) {
  vector<int> res;
  int n = SZ(vec);
  if (n - k + 1 <= 0) {
    return vector<int>();
  }
  res.resize(n - k + 1);
  vector<int> que;
  int beg;
  for (int i = 0; i < SZ(vec); i++) {
    while (!que.empty() && vec[que.back()] >= vec[i]) {
      que.pop_back();
    }
    que.PB(i);
    beg = min(beg, SZ(que) - 1);
    if (que[beg] <= i - k) {
      beg++;
    }
    if (i >= k - 1) {
      res[i - k + 1] = vec[que[beg]];
    }
  }
  RE (i, k - 1) {
    res.PB(N);
  }
  return res;
}
// vector<int> MaxK(vector<int> vec, int k) {
//   for (auto& a : vec) {
//     a *= -1;
//   }
//   VI v = MinK(vec, k);
//   for (auto& a : v) {
//     a *= -1;
//   }
//   return v;
// }
int SAinv[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  /*s[1] = 1;
  s[2] = 2;
  s[3] = 1;
  s[4] = 1;
  s[5] = 2;
  
  suffixArray(s + 1, SA + 1, 5, 2);
  RE (i, 5) {
    cerr<<SA[i]<<" ";
  }
  cerr<<"\n";
  2 3 0 4 1*/ 
/*
void suffixArray(int* s, int* SA, int n, int K) {*/
  
  make(string, br);
  int n = SZ(br);
  br = ' ' + br;
  RE (i, n) {
    if (br[i] == '(') {
      s[i] = 1;
    } else {
      s[i] = 2;
    }
  }
  VI bilv(2 * n + 5);
  bilv.PB(0);
  FOR (i, n + 1, 2 * n) {
    s[i] = s[i - n];
    br += br[i - n];
  }
  int b = 0;
  RE (i, 2 * n) {
    if (s[i] == 1) {
      b++;
    } else {
      b--;
    }
    bilv[i] = b;
  }
  int bil = bilv[n];
  suffixArray(s + 1, SA + 1, 2 * n, 2);
  RE (i, 2 * n) {
    SAinv[SA[i] + 1] = i;
  }
  VI mins = MinK(bilv, n);
  //if (bil >= 0) {
  debugv(bilv);
  debugv(mins);
  debug2(n, bil);
  
  int best = 0;
  SAinv[0] = N;
  FOR (i, 0, n - 1) {
    if (mins[i + 1] >= bilv[i] + min(0ll, bil)) {
      if (SAinv[i + 1] < SAinv[best]) {
        debug(i + 1);
        best = i + 1;
      }
    } 
  }
  cerr<<"SAinv:\n";
  RE (i, n) {
    cerr<<SAinv[i]<<" ";
  }
  cerr<<"\n";
  debug(best);
  if (bil < 0) {
    RE (i, -bil) {
      cout<<'(';
    }
  }
  FOR (i, best, best + n - 1) {
    cout<<br[i];
  }
  if (bil >= 0) {
    RE (i, bil) {
      cout<<')';
    }
  }
  cout<<"\n";
  //}
  /*else {
    int best = 0;
    FOR (i, 1, n) {
      if (mins[i + 1] >= */
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}