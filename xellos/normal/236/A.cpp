// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
// mylittlepony
using namespace std;
using namespace std::tr1;
	
int main() {
	string s;
	cin >> s;
	int poc[26];
	for(int i =0; i < 26; i++) poc[i] =0;
	for(int i =0; i < s.length(); i++) poc[s[i]-'a']++;
	int x =0;
	for(int i =0; i < 26; i++) if(poc[i] > 0) x++;
	if(x%2 == 0) printf("CHAT WITH HER!\n");
	else printf("IGNORE HIM!\n");
	return 0;}
        
// look at my code
// my code is amazing