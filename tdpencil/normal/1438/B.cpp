    #include<bits/stdc++.h>
    using namespace std;
    using ll = long long;
    #define vll vector<long long>
    int main() {
    	ll a;
    	cin >> a;
    	while(a--) {
    		ll b;
    		cin >> b;
    		vector<int> x(b);
    		for(int i =0; i <b; i++) {
    			cin >> x[i];
    		}
    		set<int> s;
    		for(int i =0; i < b; i++) {
    			s.insert(x[i]);
    		}
    		if(s.size()<=b-1) {
    			puts("YES\n");
    		} else {
    			puts("NO\n");
    		}
    	}
    }