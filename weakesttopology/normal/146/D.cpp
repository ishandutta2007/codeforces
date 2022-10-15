#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    int a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;

    string S;
    int fours = 0, sevens = 0;
    if (a3 >= a4)
    {
        fours = a3;
        sevens = a3;

        if (a3 == a4 && a1 < a3 + 1)
        {
            S.append("7");
            sevens++;
        }
        for (int i = 0; i < a3; ++i)
            S.append("47");
        if (a3 == a4 && !(a1 < a3 + 1))
        {
            S.append("4");
            fours++;
        }
    }
    else
    {
        fours = sevens = a4;
        for (int i = 0; i < a4; ++i)
            S.append("74");
    }

    if (abs(a3 - a4) > 1 || a1 < fours || a2 < sevens)
    {
        cout << -1 << endl;
        exit(0);
    }


    int i = 0;
    while (S[i] != '4')
        ++i;

    int j = S.size() - 1;
    while (S[j] != '7')
        --j;

    for (int k = 0; k < (int)S.size(); ++k)
    {
        if (k == i)
            for (int z = 0; z < a1 - fours; ++z)
                cout << '4';
        if (k == j)
            for (int z = 0; z < a2 - sevens; ++z)
                cout << '7';

        cout << S[k];
    }
    cout << endl;


    exit(0);
}