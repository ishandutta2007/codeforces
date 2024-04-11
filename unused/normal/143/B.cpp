#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    bool m = false;

    if (str[0] == '-')
    {
        m = true;
        str.erase(str.begin());
    }

    string A, B;

    auto p = str.find('.');
    if (p == str.npos)
    {
        A = move(str);
        B = "00";
    }
    else
    {
        A = str.substr(0, p);
        B = str.substr(p + 1, 2);
        B += string(2 - B.size(), '0');
    }

    if (m) printf("(");
    printf("$");

    string C;
    for (int i = 0; i < A.size(); i++)
    {
        C += A[A.size() - 1 - i];
        if (i + 1 < A.size() && i % 3 == 2) C += ',';
    }
    reverse(C.begin(), C.end());

    printf("%s.%s", C.c_str(), B.c_str());
    if (m) printf(")");
    printf("\n");
}