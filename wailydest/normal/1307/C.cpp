#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main()
{
    char ch;
    map<pair<char, char>, long long> combinations;
    map<char, int> read_amount;
    
    for (char i = 'a'; i <= 'z'; ++i) read_amount[i] = 0;
    
    string str;
    cin >> str;
    
    for (int j = 0; j < str.length(); ++j) {
        ch = str[j];
        for (auto i : read_amount) {
            combinations[make_pair(i.first, ch)] += read_amount[i.first];
        }
        ++read_amount[ch];
    }
    
    long long maximum = 1;
    for (auto i : combinations) {
        if (maximum < i.second) maximum = i.second;
    }
    for (auto i : read_amount) {
        if (maximum < i.second) maximum = i.second;
    }
    
    cout << maximum << '\n';
    
    return 0;
}