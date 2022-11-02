#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int Q;
ll A, B;
string S;

int main(){
	cin >> Q;
	while(Q--){
		cin >> A >> B;
		int cnta=0, cntb=0, cnt2b=0;
		cin >> S;
		S.push_back('X');
		int lastI = -1;
		ll m = 0;
		for(int i=0; i<sz(S); i++){
			if(S[i] == 'X'){
				ll len = i-lastI-1;
				m = max(m, len);
				lastI = i;
				if(len >= 2*B)
					cnt2b++;
				if(len >= A){
					cnta++;
				}
				else if(len >= B){
					cntb++;
				}
			}
		}
		//cout << m << " " << cnta << " " << cntb << " " << cnt2b << endl;
		if(cnta == 0)
			cout << "no\n";
		else{
			bool pos = false;
			cnta--;
			if(m >= 2*B)
				cnt2b--;
			for(int i=0; i<=m-A; i++){
				if(i >= 2*B)
					cnt2b++;
				if(i >= A){
					cnta++;
				}
				else if(i >= B){
					cntb++;
				}
				if(m-A-i >= 2*B)
					cnt2b++;
				if(m-A-i >= A){
					cnta++;
				}
				else if(m-A-i >= B){
					cntb++;
				}

				if(cntb == 0 && cnt2b == 0 && cnta%2 == 0)
					pos = true;

				if(i >= 2*B)
					cnt2b--;
				if(i >= A){
					cnta--;
				}
				else if(i >= B){
					cntb--;
				}
				if(m-A-i >= 2*B)
					cnt2b--;
				if(m-A-i >= A){
					cnta--;
				}
				else if(m-A-i >= B){
					cntb--;
				}
			}
			if(pos)
				cout << "yes\n";
			else
				cout << "no\n";
		}
		/*
		if(2*B > A){
			if(cntb > 0 || cnt2b > 1 || cnta == 0){
				cout << "no\n";
			}
			else if(cnt2b == 1){
				if(cnta % 2){
					if(m < A+2*B-1)
						cout << "yes\n";
					else if(m < 3*A)
						cout << "no\n";
					else if(m < A*4*B-1)
						cout << "yes\n";
					else
						cout << "no\n";
				}
				else{
					if(m < 2*A)
						cout << "no\n";
					else if(m < A+3*B-1)
						cout << "yes\n";
					else
						cout << "no\n";
				}
			}
			else{
				if(cnta % 2){
					cout << "yes\n";
				}
				else{
					cout << "no\n";
				}
			}
		}
		else{
			if(cnta + cntb > 1 || cnta == 0){
				cout << "no\n";
			}
			else if(m < A + 2*B-1){
				cout << "yes\n";
			}
			else{
				cout << "no\n";
			}
		}
		*/
	}

  return 0;
}