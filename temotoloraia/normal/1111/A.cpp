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

const int N = 210000;

int mas[N];

int main()
{
    ios_base::sync_with_stdio(false);
    mas['a' - 'a'] = 1;
    mas['e' - 'a'] = 1;
    mas['i' - 'a'] = 1;
    mas['o' - 'a'] = 1;
    mas['u' - 'a'] = 1;
    string a, b;
    cin >> a >> b;
    if ((int)a.size() != (int)b.size()){
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < (int)a.size(); i++){
        if (mas[a[i] - 'a'] != mas[b[i] - 'a']){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}