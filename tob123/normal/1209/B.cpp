#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N;
string S;
int on[30000];

int main(){
	cin >> N;
	cin >> S;
	for(int i=0; i<N; i++){
		int a, b;
		cin >> a >> b;
		if(S[i] == '1'){
			for(int j=0; j<b; j++){
				on[j]++;
			}
			b += a;
		}
		for(int k=0; k<100; k++){
			for(int j=0; j<a; j++){
				on[b+j]++;
			}
			b += 2*a;
		}
	}
	int m = 0;
	for(int i=0; i<200; i++){
		m = max(m, on[i]);
	}
	cout << m << endl;

  return 0;
}