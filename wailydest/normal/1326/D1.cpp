#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool ispalindrome(string str)
{
    int n = str.size();
    for (int i = 0; i < n / 2; ++i) if (str[i] != str[n - i - 1]) return false;
    return true;
}

void solve()
{
    string str;
    cin >> str;
    
    int n = str.size();
    
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
    string max_palindrome = "";
    for (int i = m - 1; i >= 0; --i) {
        if (ispalindrome(search.substr(i, m - i))) max_palindrome = search.substr(i, m - i);
        //cout << max_palindrome << '\n';
    }
    //cout << '$' << max_palindrome;
    reverse(search.begin(), search.end());
    for (int i = m - 1; i >= 0; --i) {
        if (m - i > max_palindrome.size() && ispalindrome(search.substr(i, m - i))) max_palindrome = search.substr(i, m - i);
        //cout << max_palindrome << '\n';
    }
    cout << str.substr(0, i) << max_palindrome << str.substr(n - i, i) << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}