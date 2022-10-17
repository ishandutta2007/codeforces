#include <iostream>
#include <iterator>
#include <unordered_set>
#include <string>
using namespace std;

string fit(string str1, string str2, int k) 
{
	string result(str2);
	for (int i = 0; i < k; ++i) if (str1[i] != str2[i]) {
		if (str1[i] != 'S' && str2[i] != 'S') result[i] = 'S';
		else if (str1[i] != 'E' && str2[i] != 'E') result[i] = 'E';
		else result[i] = 'T';
	}
	return result;
}

int main() 
{
	int n, k;
	cin >> n >> k;
	
	string card[1500];
	unordered_set<string> cards;
	for (int i = 0; i < n; ++i) {
		cin >> card[i];
		cards.insert(card[i]);
	}
	
	long long amount = 0;
	for (int i = 0; i < n - 1; ++i) for (int j = i + 1; j < n; ++j) amount += cards.count(fit(card[i], card[j], k));
	
	cout << amount / 3 << '\n';
	
	return 0;
}