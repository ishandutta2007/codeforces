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
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        char L[3] = { 'R', 'P', 'S' };
        char M[3] = { 'S', 'R', 'P' };
        int A[3]; cin >> A[0] >> A[1] >> A[2];
        string S; cin >> S;

        int B[3] = { 0 };
        for (int i = 0; i < n; ++i)
        {
            int j;
            for (j = 0; j < 3; ++j)
                if (S[i] == M[j])
                    break;
            B[j]++;
        }

        int num = 0;
        int C[3] = { 0 };
        for (int i = 0; i < 3; ++i)
        {
            C[i] = min(A[i], B[i]);
            num += C[i];
        }

        if (num >= (n + 1) / 2)
        {
            cout << "YES\n";

            vector<char> spare;
            for (int i = 0; i < 3; ++i)
                spare.insert(spare.end(), A[i] - C[i], L[i]);

            for (int i = 0; i < n; ++i)
            {
                int j;
                for (j = 0; j < 3; ++j)
                    if (S[i] == M[j])
                        break;

                if (C[j] > 0)
                {
                    cout << L[j];
                    C[j]--;
                }
                else
                {
                    cout << spare.back();
                    spare.pop_back();
                }
            }
            cout << endl;
        }
        else
            cout << "NO\n";
    }

    exit(0);
}