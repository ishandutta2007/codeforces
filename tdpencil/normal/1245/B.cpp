#include <bits/stdc++.h>

#define rep(i,j,n) for(int i = j; i < n; i++)
#define vi vector<int>
#define all(x) begin(x), end(x);
#define double long double
int main() {
    using namespace std;

    int T = 1;
    cin >> T;
    for(int test_case = 0; test_case < T; test_case++) {
        // the rule is a[1] = 1
        // a[2 * i] = a[i] + 1 
        // a[2 * i  + 1] = 1
        //

        array<int, 3> lit;
        int N; cin >> N;
        rep(i,0,3)
            cin >> lit[i];
        vector<vector<int>> C(3);
        string S; cin >> S;
        for(int i = 0; i < S.size(); i++)
            if(S[i] == 'R')
                C[0].emplace_back(i);
            else if(S[i] == 'P')
                C[1].emplace_back(i);
            else if(S[i] == 'S')
                C[2].emplace_back(i);
        string A;
        for(int i = 0; i < N; i++)
            A+= '0';
        int toBeat = (N % 2) + N / 2; 
        for(int j : C[0])
            if(lit[1] > 0)
                A[j] = 'P', toBeat--, lit[1]--;
        for(int j : C[1])
            if(lit[2] > 0)
                A[j] = 'S', toBeat--, lit[2]--;
        for(int j : C[2])
            if(lit[0] > 0)
                A[j] = 'R', toBeat--, lit[0]--;

        if(toBeat > 0) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
            for(int j = 0; j < 3; j++)
                for(int i : C[j])
                    if(A[i] == '0') {
                        if(lit[0]) {A[i] = 'R', lit[0]--;}
                        else if(lit[1])
                            A[i] = 'P', lit[1]--;
                        else if(lit[2])
                            A[i] = 'S', lit[2]--;
                    }
            cout << A << '\n';

        }



    }
}