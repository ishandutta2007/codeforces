#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

const int N = 2100000;

int m, k, n, s;

int a[N], b[N];

int num, g;

map < int, int > M, MM;

int I;
bool F[N];

vector < int > v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> k >> n >> s;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= s; i++){
        cin >> b[i];
        MM[b[i]]++;
        if (MM[b[i]] == 1)
            g++;
    }
    num = m - n * k + k;
    for (int i = 0; i < num; i++){
        M[a[i]]++;
        if (M[a[i]] == MM[a[i]])
            g--;
    }
    for (int i = 1; i + num <= m + 1 || i == 1; i++){
        M[a[i - 1]]--;
        if (M[a[i - 1]] == MM[a[i - 1]] - 1){
            g++;
            //cout << i << endl;
        }
        M[a[i + num - 1]]++;
        if (M[a[i + num - 1]] == MM[a[i + num - 1]])
            g--;
        //cout << g << " " << num << endl;
        if (g == 0 && (i - 1) % k == 0){
            I = i;
            break;
        }
    }
    if (I == 0){
        cout << -1 << endl;
        return 0;
    }
    M.clear();
    num -= k;
    for (int i = I; i < I + m - n * k + k && i <= m; i++){
        if (MM[a[i]] == 0 && num){
            F[i] = 1;
            num--;
        }
        else
            MM[a[i]]--;
    }
    for (int i = 1; i <= m; i++)
        if (F[i])
            v.pb (i);
    cout << (int)v.size() << endl;
    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}