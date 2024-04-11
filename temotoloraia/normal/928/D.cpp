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
const int MOD = 1e9 + 7;
int ans;
string Str;
set < string > S;
set < string >:: iterator I;
int check (string s1, string s2){
    for (int i = 0; i < s1.size() && i < s2.size(); i++)
        if (s1[i] != s2[i])
            return i;
    return min (s1.size(), s2.size());
}
void f (string s){
    if (s == "")
        return;
    ans += s.size();
    if (S.size() == 0){
        S.insert(s);
        return;
    }
    string str = "";
    I = S.upper_bound (s);
    if (I == S.begin()){
        S.insert(s);
        return;
    }
    I--;
    string s1 = (*I);
    if (check (s,s1) < s1.size()){
        S.insert(s);
        return;
    }
    int p = s1.size()-2;
    I++;
    if (I != S.end()){
        string s2 = (*I);
        p = check (s1,s2);
        if (p >= s1.size()){
            S.insert(s);
            return;
        }
        p = s1.size() - p - 2;
    }
    I--;
    if (I != S.begin()){
            I--;
        string s2 = (*I);
        int k = check (s1, s2);
        p = min (p, (int)s1.size() - k - 2);
    }
    if (p < 0)
        p=0;
    ans -= p;
    S.insert(s);
}
int main()
{
    while (getline (cin, Str)){
        ans++;
        string s = "";
        for (int i = 0; i < Str.size(); i++){
            if (Str[i] < 'a' || 'z' < Str[i]){
                ans++;
                f (s);
                s = "";
                continue;
            }
            else
                s+=Str[i];
        }
        f(s);
    }
    cout<<ans<<endl;
    return 0;
}