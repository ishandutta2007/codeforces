#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void z_function(string str, int n, int *z)
{
    int l, r;
    l = r = 0;
    z[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (i >= r) {
            z[i] = 0;
            int j = i;
            while (str[j] == str[z[i]] && j < n) {
                ++j;
                ++z[i];
            }
            if (z[i]) {
                r = i + z[i] - 1;
                l = i;
            }
        }
        else {
            if (z[i - l] + i <= r) {
                z[i] = z[i - l];
            }
            else {
                z[i] = r - i + 1;
                int j = r + 1;
                while (str[j] == str[z[i]] && j < n) {
                    ++j;
                    ++z[i];
                }
                r = i + z[i] - 1;
                l = i;
            }
        }
    }
}


void solve()
{
    string str;
    cin >> str;
    
    long long n = str.size();
    
    int i = 0;
    while (i <= n / 2 && str[i] == str[n - i - 1]) {
        ++i;
    }
    if (i == n / 2 + 1) {
        cout << str << '\n';
        return;
    }
    string search = str.substr(i, n - 2 * i);
    int m = search.size();
    
    string reversed = search;
    reverse(reversed.begin(), reversed.end());
    
    string candidate = search + '$' + reversed;
    //cout << candidate;
    
    int z[2000001];
    z_function(candidate, 2 * m + 1, z);
    
    int max_palindrome_start = m - 1;
    for (int i = m + 1; i < 2 * m + 1; ++i) {
        if (z[i] + i == 2 * m + 1 && m - max_palindrome_start < 2 * m + 1 - i) max_palindrome_start = i - m - 1;
    }
    
    string max_palindrome = reversed.substr(max_palindrome_start, m - max_palindrome_start);
    
    candidate = reversed + '$' + search;
    
    z_function(candidate, 2 * m + 1, z);
    
    max_palindrome_start = m - 1;
    for (int i = m + 1; i < 2 * m + 1; ++i) {
        if (z[i] + i == 2 * m + 1 && m - max_palindrome_start < 2 * m + 1 - i) max_palindrome_start = i - m - 1;
    }
    
    if (m - max_palindrome_start > max_palindrome.size()) max_palindrome = search.substr(max_palindrome_start, m - max_palindrome_start);
    
    cout << str.substr(0, i) << max_palindrome << str.substr(n - i, i) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}