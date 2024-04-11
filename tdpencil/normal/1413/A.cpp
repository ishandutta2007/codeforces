#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using it = int64_t;

int main() {
	it a;
	scanf("%lld", &a);
	while(a--){
		it n;
		scanf("%lld",&n);
		vector<it> vt(n);
        vector<it> answers;
        for(it i=0;i<n;i++){
            scanf("%lld",&vt[i]);
        }
        for(it i =0; i < n; i+=2) {
            answers.push_back(-vt[i+1]);
            answers.push_back(vt[i]);
        }
        for(auto & x : answers) {
            cout << x << " ";
        }
        cout << '\n';
	}
}