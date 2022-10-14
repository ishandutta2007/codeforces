#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mxN = 3e5;


struct edge {
    vector<int> adjList;
    int cost;
};  

vector<edge> graph(5001);



int main() {
    int t; scanf("%d", &t);

    for(int test_case =0; test_case < t; test_case++){
        int n; scanf("%d", &n);
        vector<int> a(n);
        for(auto &i : a) {
            scanf("%d", &i);
        }
        bool works=1;
        for(int i = 0 ; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(a[i]!=a[j]) {
                    works=0;
                }
            }
        }

        if(works) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int root = a[0];
            int choice = -1;

            for(int i = 0; i < n; i++) {
                if(a[i] != root) {
                    cout << 1 << " " << i + 1 << "\n";
                    choice = i;
                }
            }

            assert(choice != -1);

            for(int i = 0; i < n; i++) {
                if(i!=0&&a[i]==root) {
                    cout << choice + 1 << " " << i + 1 << "\n";
                }
            }
        }
    }
}