#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MAXN = 200000;
string s;
string ss[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
int main()
{
    cin>>s;
    int n = (int)s.size();
    int p = 0;
    for (int i = 0; i < n; ++i){
        string str = "";
        for (int j = i; j < n; ++j){
            str += s[j];
            for (int l = 0; l < 5; ++l)
                if (str == ss[l])
                    ++p;
        }
    }
    if (p == 1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}