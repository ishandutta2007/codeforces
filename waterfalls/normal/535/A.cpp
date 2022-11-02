#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string digits[10] = {string("zero"),string("one"),string("two"),string("three"),string("four"),
                     string("five"),string("six"),string("seven"),string("eight"),string("nine")};
string teens[10] = {string("ten"),string("eleven"),string("twelve"),string("thirteen"),string("fourteen"),
                    string("fifteen"),string("sixteen"),string("seventeen"),string("eighteen"),string("nineteen")};
string tens[10] = {string("zero"),string("ten"),string("twenty"),string("thirty"),string("forty"),
                   string("fifty"),string("sixty"),string("seventy"),string("eighty"),string("ninety")};

int main() {
    int s;
    cin >> s;
    if (s<10) cout << digits[s];
    else if (s<20) cout << teens[s-10];
    else if (s%10==0) cout << tens[s/10];
    else cout << tens[s/10] << "-" << digits[s%10];

    return 0;
}