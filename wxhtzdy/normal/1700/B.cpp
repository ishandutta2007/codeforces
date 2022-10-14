#include <bits/stdc++.h>

using namespace std;

string findDiff(string str1, string str2)
{

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits

        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);

        // If subtraction is less than zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);

        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    while (str.back() == '0') str.pop_back();

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string d;
    cin >> d;
    if (d[0] < '9') {
      for (int i = 0; i < n; i++) {
        cout << (int) ('9' - d[i]);
      }
      cout << '\n';
    } else {
      string s = string(n + 1, '1');
      cout << findDiff(s, d) << '\n';
    }
  }
  return 0;
}