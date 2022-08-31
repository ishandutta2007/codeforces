#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <complex>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

ld PI = acos((ld) -1.);
typedef complex <double> C;
const C I(0,1);

struct FFT
{
    vector <C> fft(int n, double theta, vector <C> a)
    {
        for (int m = n; m >= 2; m >>= 1)
        {
            int mh = m >> 1;
            for (int i = 0; i < mh; i++)
            {
                C w = exp(i*theta*I);
                for (int j = i; j < n; j += m)
                {
                    int k = j + mh;
                    C x = a[j] - a[k];
                    a[j] += a[k];
                    a[k] = w * x;
                }
            }
            theta *= 2;
        }
        int i = 0;
        for (int j = 1; j < n - 1; j++)
        {
            for (int k = n >> 1; k > (i ^= k); k >>= 1);
            if (j < i) swap(a[i], a[j]);
        }
        return a;
    }
    vector <int> getFFT(vector <int> A,vector <int> B)
    {
        vector <C> x,b;
        for(int i=0;i<A.size()+B.size();i++)
        {
            x.push_back(C(i<A.size()?A[i]:0,0));
            b.push_back(C(i<B.size()?B[i]:0,0));
        }
        int N=1;
        while(N<x.size()) N<<=1;
        while(x.size()<N) x.push_back(C(0,0)),b.push_back(C(0,0));
        x=fft(N,2*PI/N,x);
        b=fft(N,2*PI/N,b);
        for(int i=0;i<N;i++) x[i]*=b[i];
        x=fft(N,-2*PI/N,x);
        vector <int> ret;
        for(int i=0;i<x.size();i++) ret.push_back((int) (x[i].real()/N+0.5));
        return ret;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int LIMIT = 500000;
    vb isp(LIMIT+1, true);
    vi mindiv(LIMIT+1, 0);
    forn(i,0,LIMIT+1) mindiv[i]=i;
    int upbound = (int)sqrt((double)LIMIT);
    vi p;
    for (int m = 2; m <= upbound; m++) {
        if (isp[m]) {
            p.pb(m);
            for (int k = m * m; k <= LIMIT; k += m) {
                isp[k] = false;
                mindiv[k]=min(mindiv[k], m);
            }
        }
    }
    
    for(int m = upbound+1; m<=LIMIT; m++) {
        if (isp[m]) {
            p.pb(m);
        }
    }


    int q;
    scanf("%d", &q);
    char c[500100];
    FFT fft;
    forn(i,0,q) {
        int n;
        scanf("%d", &n);
        scanf("%s", c);
        string s(c);
//        cout<<s<<endl;
        int bit = 0;
        int d2 = 1;
        while(d2 < n) {
            bit++;
            d2 *= 2;
        }
        bit++;
        
        vi a(n,0);
        vi b(n,0);
        forn(i,0,n) {
            if(s[i] == 'V') a[i] = 1;
            if(s[i] == 'K') b[n-1-i] = 1;
        }
        vi c = fft.getFFT(a, b);
        vi can(n+1,0);
        forn(i,0,c.size()) if(c[i] != 0) can[abs(n-1-i)] = 1;
        for(int i = n; i >= 1; i--) {
            if(can[i]) {
                int cur = i;
                while(cur > 1) {
                    int cp = mindiv[cur];
                    can[i/cp] = 1;
                    cur/=cp;
                    while(cur%cp==0) cur/=cp;
                }
            }
        }
        vi ans;
        forn(i,1,n+1) if(!can[i]) ans.pb(i);
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d ", x);
        printf("\n");
    }
}