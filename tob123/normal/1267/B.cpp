#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n = 2e5 + 5;

int N;
string C;
int main(){
	cin >> C;
	N = C.size();
	int c = 0, i = 0, j = N-1;
	while(true){
		if(i+1 >= j){
			if(i==j) c = 0;
			else c = j-i+2;
			break;
		}
		int ni = i, nj = j;
		if(C[i] == C[j] && (C[i+1] == C[i] || C[j-1] == C[j])){
			while(ni+1 < N && C[ni+1] == C[i])
				ni++;
			while(nj-1 >= 0 && C[nj-1] == C[j])
				nj--;
			if(ni > nj){
				c = j-i+2;
				break;
			}else{
				i = ni+1;
				j = nj-1;
			}
		}else{
			break;
		}
	}
	cout << c << endl;
	return 0;
}