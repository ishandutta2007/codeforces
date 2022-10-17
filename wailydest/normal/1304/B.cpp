#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

int main() 
{
    set<string> strings;
    vector<string> palindromes;
    string middle_element;
    bool is_middle_element_set = false;
    string str, reversed;
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        cin >> str;
        strings.insert(str);
    }
    
    while (strings.size()) 
	{
		str = reversed = *strings.begin();
		reverse(reversed.begin(), reversed.end());
		if (!str.compare(reversed)) {
			if (!is_middle_element_set) {
				middle_element = str;
				is_middle_element_set = true;
			}
		}
		else {
			if (strings.count(reversed)) {
				palindromes.push_back(str);
				strings.erase(reversed);
			}
		}
		strings.erase(str);
	}
    
	cout << (palindromes.size() * 2 + is_middle_element_set) * m << '\n';
	
    for (int i = 0; i < palindromes.size(); ++i) cout << palindromes[i];
	if (is_middle_element_set) cout << middle_element;
	for (int i = 0; i < palindromes.size(); ++i) {
		str = palindromes[i];
		reverse(str.begin(), str.end());
		palindromes[i] = str;
	}
	for (int i = palindromes.size() - 1; i >= 0; --i) cout << palindromes[i];
	cout << '\n';
    
    return 0;
}