#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5;
const int mod = (int)1e9 + 7;
int cnt[N];
int p[N];


int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]); 
        p[i]--;
    }

    for (int i = 0; i < n; i++)
    {
        cnt[i] = 1;
        for (int s = p[i]; s < i; s++)
        {
            cnt[i] = (cnt[i] + cnt[s] + 1) % mod;
        }   
    }
    int ans = 0;                   
    for (int i = 0; i < n; i++)
    {
        ans = (ans + cnt[i] + 1) % mod;
    }
    cout << ans;

    return 0;
}