#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <unordered_map>
using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<string> directories;
	for(int i=0; i<n; ++i) {
		string cmd;
		cin >> cmd;
		if(cmd=="pwd") {
			cout << '/';
			for(string directory : directories)
				cout << directory << '/';
			cout << '\n';
		} else {
			string directory;
			cin >> directory;
			if(directory[0]=='/')
				directories.clear();
			directory+='/';
			int pos=0;
			while((pos=directory.find("/"))!=string::npos) {
				string token=directory.substr(0, pos);
				if(token=="..")
					directories.pop_back();
				else if(pos!=0)
					directories.push_back(token);
				directory.erase(0, pos+1);
			}
		}
	}

	return 0;
}