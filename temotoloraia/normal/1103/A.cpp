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

const ll N = 1005;

string S;
int a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>S;
    for (int i = 0; i < (int)S.size(); i++){
        if (S[i] == '0'){
            cout << "1 " << a + 1 << endl;
            a++;
            a %= 4;
        }
        else {
            cout << "3 " << b + 1 << endl;
            b += 2;
            b %= 4;
        }
    }
    return 0;
}