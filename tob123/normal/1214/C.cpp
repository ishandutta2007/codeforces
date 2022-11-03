#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N;
string S;

int main(){
	cin >> N;
	cin >> S;
	int ind = -1;
	for(int i=N-1; i>=0; i--){
		if(S[i] == '('){
			ind = i;
			break;
		}
	}
	if(ind == -1){
		cout << "No" << endl;
		return 0;
	}
	int cnt = 1;
	for(int i=0; i<N; i++){
		if(i == ind)
			continue;
		if(S[i] == '('){
			cnt++;
		}
		else{
			cnt--;
			if(cnt < 0){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	if(cnt == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

  return 0;
}