#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

#ifdef UMQRA
    #define getTime() fprintf(stderr, "Running time:%.3lf seconds\n", (double)(clock()) / CLOCKS_PER_SEC)
#else
    #define getTime()
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

long long gcd(ll a, ll b)
{
    return (b % a == 0 ? a : gcd(b, a % b));
}

struct Fraction
{
    ll a, b;
    Fraction () {}
    Fraction (ll a, ll b) : a(a), b(b) {}   
    Fraction operator / (Fraction x)
    {
        ll na = a * x.b;
        ll nb = b * x.a;
        ll d = gcd(na, nb);
        return Fraction(na / d, nb / d);
    }
    Fraction operator * (Fraction x)
    {
        ll na = a * x.a;
        ll nb = b * x.b;
        ll d = gcd(na, nb);
        return Fraction(na / d, nb / d);
    }
    Fraction operator + (Fraction x)
    {
        ll z = b * x.b;
        ll t = a * x.b + b * x.a;
        ll d = gcd(z, t);
        return Fraction(t / d, z / d);
    }
};

int a[(int)1e5 + 100];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);

    ll sumC = 0;
    ll z = 0;
    for (int i = 0; i < n; i++)
    {                                           
        z += 2 * ((ll)(i + 1) * (ll)a[i] - sumC);
        z -= a[i];
        sumC += a[i];
    }
    ll d = gcd(z, n);
    cout << z / d << ' ' << n / d << endl;
    

    return 0;
}