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
const int N = 105;
int n, a[N],  b[N];
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        b[a[i]]++;
    }
    int num = 0;
    for (int i = 1; i <= 100; i++)
        if (b[i] == 1)
            num++;
    if (num % 2 == 0){
        cout<<"YES\n";
        num /= 2;
        for (int i = 1; i <= n; i++){
            if (b[a[i]] == 1 && num > 0){
                cout<<"A";
                num--;
                continue;
            }
            cout<<"B";
        }
        return 0;
    }
    string s = "";
    num /= 2;
    for (int i = 1; i <= n; i++){
        if (b[a[i]] == 1 && num > 0){
            s += "A";
            num--;
            continue;
        }
        s += "B";
    }
    bool ok = 0;
    for (int i = 1; i <= n; i++)
    if (b[a[i]] > 2){
        s[i-1] = 'A';
        ok = 1;
        break;
    }
    if (ok == 0){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n"<<s<<endl;
    return 0;
}