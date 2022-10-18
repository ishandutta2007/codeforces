using namespace std;
#include <cstdio>
#include <string>
#include <iostream>
string t1[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string t2[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string t3[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

int main() {
    int n;
    scanf("%d", &n);
    if (n < 10) cout << t2[n];
    else if (n < 20) cout << t3[n-10];
    else {
        cout << t1[n/10];
        if (n%10) cout << "-" << t2[n%10];
    }
}