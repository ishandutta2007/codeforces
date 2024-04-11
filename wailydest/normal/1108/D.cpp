#include <iostream>
#include <vector>
#include <string>
using namespace std;

char another(char ch1, char ch2) 
{
	if (ch1 != 'R' && ch2 != 'R') return 'R';
	if (ch1 != 'G' && ch2 != 'G') return 'G';
	return 'B';
}

int main() 
{
	int n;
	string str;
	
	cin >> n;
	cin >> str;
	
	vector<pair<char, int> > same_colors;
	
	int same = 1;
	while (str[same] == str[same - 1]) ++same;
	same_colors.push_back(make_pair(str[0], same));
	
	for (int i = same; i < n; ++i) {
		if (str[i] == (same_colors.end() - 1)->first) ++((same_colors.end() - 1)->second);
		else same_colors.push_back(make_pair(str[i], 1));
	}
	
	int changes_amount = 0;
	
	for (vector<pair<char, int> >::iterator it = same_colors.begin(); it != same_colors.end(); ++it) changes_amount += it->second / 2;
	
	cout << changes_amount << '\n';
	
	char tochange = another(same_colors.begin()->first, 'R');
	for (int i = same_colors.begin()->second - 1; i >= 0; --i) 
		cout << (i % 2 ? tochange : same_colors.begin()->first);
	
	for (vector<pair<char, int> >::iterator it = same_colors.begin() + 1; it != same_colors.end(); ++it) {
		tochange = another((it - 1)->first, it->first);
		for (int i = it->second - 1; i >= 0; --i) cout << (i % 2 ? tochange : it->first);
	}
	
	return 0;
}