#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define ins insert
#define X first
#define Y second
#define fin(name) freopen(name, "r", stdin)
#define fout(name) freopen(name, "w", stdout)
#define files(name) fin(name".in"); fout(name".out")
#define endl "\n"
#define fi(st,n) for (int i = (st); i <= (int)(n); ++i)
#define fj(st,n) for (int j = (st); j <= (int)(n); ++j)
#define fk(st,n) for (int k = (st); k <= (int)(n); ++k)
#define fq(st,n) for (int q = (st); q <= (int)(n); ++q)
#define fw(st,n) for (int w = (st); w <= (int)(n); ++w)
#define ff(i, st, n) for (int (i) = (st); (i) <= (int)(n); ++(i))
#define ei(st,n) for (int i = (st); i >= (int)(n); --i)
#define ej(st,n) for (int j = (st); j >= (int)(n); --j)
#define ek(st,n) for (int k = (st); k >= (int)(n); --k)
#define ef(i, st, n) for (int (i) = (st); (i) >= (int)(n); --(i))
#define ri(st,n) for (int i = (st); i < (int)(n); ++i)
#define rj(st,n) for (int j = (st); j < (int)(n); ++j)
#define rk(st,n) for (int k = (st); k < (int)(n); ++k)
#define rq(st,n) for (int q = (st); q < (int)(n); ++q)
#define rf(i, st, n) for (int (i) = (st); (i) < (int)(n); ++(i))
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define y1 dsklmlvmd

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const dbl eps = (dbl) 1e-8;
const int mod = (int) 1e9 + 7;
const int maxn = (int) 1e6 + 5;
const int MX = (int) 1e5;
//const dbl M_PI = (dbl)2 * (dbl)acos(0);

//cout<<fixed<<setprecision(15);
//srand(time(0));

ll a[105][105][105];
ll d[maxn], tod[maxn];
ll st[maxn], en[maxn], p[maxn];
ll L, n, m;
ll h[105];

void mat_pow(int z, int st)
{
	clean(a[z]);
	if (st == 0)
	{
		fi(0, m - 1)
			a[z][i][i] = 1;
		return;
	}
	if (st & 1)
	{
		mat_pow(z + 1, st - 1);
		fi(0, m - 1)
			fj(0, m - 1)
				fk(0, m - 1)
				{
					a[z][i][j] = (a[z][i][j] + a[z + 1][i][k] * a[0][k][j]) % mod;
				}
	}
	else
	{
		mat_pow(z + 1, st / 2);
		fi(0, m - 1)
			fj(0, m - 1)
				fk(0, m - 1)
				{
					a[z][i][j] = (a[z][i][j] + a[z + 1][i][k] * a[z + 1][k][j]) % mod;
				}
	}
}

int main()
{
//    fin("t.in");
    sync;
    cin >> n >> L >> m;
    fi(1, n)
    	cin >> st[i];
    fi(1, n)
    	cin >> p[i];
    fi(1, n)
    	cin >> en[i];
    clean(d);
    fi(1, n)
    	++d[st[i] % m];
    clean(a[0]);

    clean(h);
    fi(1, n)
    {
    	++h[p[i] % m];
    }

    fi(0, m - 1)
    	fj(0, m - 1)
    	{
    		a[0][(j + i) % m][i] += h[j];
    		a[0][(j + i) % m][i] %= mod;
    	}

    mat_pow(1, L - 2);
    /*
    fi(0, m - 1)
    {
    	fj(0, m - 1)
    	{
    		cout << a[1][i][j] << " ";
    	}
    	cout << endl;
    }
    return 0;
	*/
    clean(tod);
    fi(0, m - 1)
    	fj(0, m - 1)
    	{
    		tod[i] += a[1][i][j] * d[j];
    		tod[i] %= mod;
    	}
    
    fi(0, m - 1)
    {
    	d[i] = tod[i];
//    	if (d[i] != 0)
//    		cout << i << " " << d[i] << endl;
    }
    clean(tod);



    clean(h);
    fi(1, n)
    {
    	h[(p[i] + en[i]) % m] += 1;
    	h[(p[i] + en[i]) % m] %= mod;
    }

    fi(0, m - 1)
    	fj(0, m - 1)
    	{
    		tod[(j + i) % m] += d[i] * h[j];
    		tod[(j + i) % m] %= mod;
    	}

    cout << tod[0] << endl;
    return 0;
}