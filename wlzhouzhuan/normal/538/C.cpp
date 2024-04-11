#include <bits/stdc++.h>
 
/*** TEMPLATE CODE STARTS HERE ***/
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;
 
#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())
 
template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}
 
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
 
static void redirect(int argc, const char **argv)
{
    ios::sync_with_stdio(false);
    if (argc > 1)
    {
        static filebuf f;
        f.open(argv[1], ios::in);
        cin.rdbuf(&f);
        if (!cin)
        {
            cerr << "Failed to open '" << argv[1] << "'" << endl;
            exit(1);
        }
    }
 
    if (argc > 2)
    {
        static filebuf f;
        f.open(argv[2], ios::out | ios::trunc);
        cout.rdbuf(&f);
        if (!cout)
        {
            cerr << "Failed to open '" << argv[2] << "'" << endl;
        }
    }
}
 
/*** TEMPLATE CODE ENDS HERE */
 
int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N, M;
    cin >> N >> M;
    int pd = 0, ph = 0;
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        int d, h;
        cin >> d >> h;
        if (i == 0)
            ans = h + d - 1;
        else
        {
            if (abs(ph - h) > abs(pd - d))
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
            else
            {
                int gap = (abs(pd - d) - abs(ph - h)) / 2;
                ans = max(ans, max(ph, h) + gap);
            }
        }
        ph = h;
        pd = d;
    }
    ans = max(ans, ph + (N - pd));
    cout << ans << '\n';
 
    return 0;
}