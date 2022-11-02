#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n = 2e5 + 5;

int T, N;

bool win(int a, int b){
	cout << "? " << a+1 << " " << b+1 << endl;
	char c;
	cin >> c;
	return c == '>';
}

int main(){
	cin >> T;
	for(int t = 0; t < T; ++t){
		cin >> N;
		set<int> S;
		for(int i = 0; i < 2*N; ++i){
			S.insert(i);
		}
		int looser = 0, winner = 1;
		if(win(looser, winner)) swap(winner, looser);

		while(true){
			int l1 = -1, w1 = -1;
			auto it = S.begin();
			while(w1 == -1){
				if(*it != looser && *it != winner){
					if(l1 == -1) l1 = *it;
					else w1 = *it;
				}
				it++;
			}
			if(win(l1, w1)) swap(w1, l1);
			//cerr << "looser: "<< looser+1 << " winner: "<< winner+1 << " l1: "<< l1+1 << " w1: "<< w1+1 << endl;
			int totL = (win(looser, l1)? l1 : looser);
			int lW = (totL == looser ? l1 : looser);
			//cerr << "totL: "<< totL+1 << " lW: "<< lW +1<< endl;
			set<int> Small, Large;
			Large.insert(winner);
			Large.insert(w1);
			Large.insert(lW);
			for(auto x : S){
				if(x != winner && x != w1 && x != lW && x != totL){
					if(win(x, totL))
						Large.insert(x);
					else
						Small.insert(x);
				}
			}
			if(Large.size() <= N){
				// sort small -> finish
				vector<int> V;
				for(int x : Small)
					V.push_back(x);
				sort(V.begin(), V.end(), win);
				
				cout << "!" << endl;
				break;
			}else{
				S = Large;
				winner = (totL == looser ? w1 : winner);
				looser = (totL == looser ? l1 : looser);
			}
		}
	}

	return 0;
}