#include <bits/stdc++.h>

using namespace std;

int N, A[100005], T;

vector<pair<int,int> > targets;
vector<int> ones, twos, threes;

int currow = 1, col[100005], twomatch[100005], threematch[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i){
		cin >> A[i];
	}
	for (int i = N; i >= 1; --i){
		if (A[i] == 1){
			ones.push_back(i);
		}
		else if (A[i] == 2){
			if (ones.size() == 0){
				cout << -1 << '\n';
				return 0;
			}
			else{
				twomatch[i] = ones.back();
				ones.pop_back();
			}
			twos.push_back(i);
		}
		else if (A[i] == 3){
			if (threes.size() > 0){
				threematch[i] = threes.back();
			}
			else if (twos.size() > 0){
				threematch[i] = twos.back();
			}
			else if (ones.size() > 0){
				threematch[i] = ones.back();
				ones.pop_back();
			}
			else{
				cout << -1 << '\n';
				return 0;
			}
			threes.push_back(i);
		}
	}
	for (int i = 1; i <= N; ++i){
		if (col[i] == 1 || A[i] == 0) continue;
		int curcol = i;
		while (curcol != 0){
			col[curcol] = 1;
			if (A[curcol] == 1){
				targets.emplace_back(currow,curcol);
				curcol = 0;
				currow++;
			}
			else if (A[curcol] == 2){
				targets.emplace_back(currow,curcol);
				curcol = twomatch[curcol];
			}
			else if (A[curcol] == 3){
				targets.emplace_back(currow,curcol);
				curcol = threematch[curcol];
				targets.emplace_back(currow,curcol);
				currow++;
			}
		}
	}
	cout << targets.size() << '\n';
	for (auto it : targets){
		cout << it.first << ' ' << it.second << '\n';
	}
}