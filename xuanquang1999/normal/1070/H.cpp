#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

const int MAXN = 10005;

int n, q;
string name[MAXN];
map<string, int> mId, mCnt;

void read(string &s) {
    char tmp[10];
    scanf("%s", tmp);
    s.assign(tmp);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        read(name[i]);
        set<string> s;
        fto(l, 0, sz(name[i])-1)
            fto(len, 1, sz(name[i])-l)
                s.insert(name[i].substr(l, len));

        for(string t: s) {
            mId[t] = i;
            ++mCnt[t];
        }
    }

    scanf("%d", &q);
    fto(i, 1, q) {
        string t; read(t);
        if (mId.find(t) == mId.end())
            puts("0 -");
        else
            printf("%d %s\n", mCnt[t], name[mId[t]].c_str());
    }

    return 0;
}