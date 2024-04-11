#include <bits/stdc++.h>
using namespace std;

bool check[200001];

int main () {
	vector<int> ans;
    vector<pair<long long,int> > big;
    long long a, b, c, d, sum = 0, coun = 0;
    cin >> a >> b >> c;
    for(int i = 0; i < a; i++){
        cin >> d;
        big.push_back(make_pair(d,i));
    }
    sort(big.begin(), big.end(), greater<pair<int,int> >());
    long long t = b*c;
    for(int i = 0; i < t; i++){
        check[big[i].second] = true;
        sum += big[i].first;
    }
    cout << sum << "\n";
    for(int i = 0; i < a; i++){
        if(check[i]){
            coun++;
        }
		if(coun == b){
            coun = 0;
            ans.push_back(i + 1);
        }
    }
    ans.pop_back();
    for(int i = 0; i < ans.size(); i++){
    	cout << ans[i] << " ";
	}
}