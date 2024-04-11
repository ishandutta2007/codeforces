#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 7010;

int N;
vector<ll> A, B;
int cntB[n];
bool vis[n];

int main(){
	cin >> N;
	A.resize(N);
	B.resize(N);
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
	for(int i=0; i<N; i++){
		cin >> B[i];
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(A[i] & (~A[j])){
				cntB[i]++;
			}
		}
	}
	/*
	for(int i=0; i<N; i++){
		for(int x : better[i])
			cout << x << " ";
		cout << "-> " << cntB[i];
		cout << endl;
	}
	*/
	int cnt = N-1;
	while(true){
		bool found = false;
		for(int i=0; i<N; i++){
			if(vis[i])
				continue;
			if(cntB[i] == cnt){
				//cout << "rem: " << i << endl;
				vis[i] = true;
				for(int j=0; j<N; j++){
					if(A[j] & (~A[i])){
						cntB[j]--;
					}
				}
				cnt--;
				found = true;
				break;
			}
		}
		if(!found)
			break;
	}
	ll sum = 0;
	for(int i=0; i<N; i++){
		if(!vis[i]){
			sum += B[i];
			//cout << i << endl;
		}
	}
	cout << sum << endl;

  return 0;
}