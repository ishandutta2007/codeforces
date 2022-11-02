#include <bits/stdc++.h>
using namespace std; const int n = 400005; int N;

vector<int> A, B, Z; 

int main(){
    cin >> N;
    int M = 0, S = 0;
    int tA = 0, tB = 0;
    int pC = 0;
    for(int i = 0; i < N; ++i){
    	string s;
    	int a;
    	cin >> s >> a;
    	if(s == "11"){
    		M++;
    		S += a;
    		tA++;
    		tB++;
    		pC++;
    	}else if(s == "00"){
    		Z.push_back(a);
    	}else if(s == "10"){
    		A.push_back(a);
    	}else if(s == "01"){
    		B.push_back(a);
    	}
    }
    if(A.size() < B.size())
    	swap(A, B);
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    int i;
    for(i = 0; i < A.size() && i < B.size(); ++i){
    	M += 2;
    	tA++;
    	tB++;
    	S += A[i] + B[i];
    }
    
    for(int j = i; j < A.size(); ++j){
    	Z.push_back(A[j]);
    }
    sort(Z.begin(), Z.end(), greater<int>());
    for(int j = 0; j < pC && j < Z.size(); ++j){
    	S += Z[j];
    }
    cout << S << endl;
}