#include<bits/stdc++.h>
using namespace std;
#define int		long long
#define double	long double
#define pb		push_back
#define pob		pop_back
#define mp		make_pair
#define fi		first
#define se		second
#define pque	priority_queue
#define endl	'\n'
typedef vector <int> 	vi;
typedef pair <int, int> ii;
typedef vector <vi > 	vvi;
typedef vector <ii > 	vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int t, n;
string s;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--){
	    cin >> s;
	    n = s.length();
	    int a = 0, b = 0, c = 0;
	    for (int i = 0; i < n; i++){
	        if ('0' <= s[i] && s[i] <= '9') a++;
	        if ('a' <= s[i] && s[i] <= 'z') b++;
	        if ('A' <= s[i] && s[i] <= 'Z') c++;
	    }
	    if (a && b && c){
	        cout << s << endl;
	        continue;
	    }
	    if (!a && b && c){
	        for (int i = 0; i < n; i++){
	            if ('a' <= s[i] && s[i] <= 'z'){
	                if (b > 1){
	                    s[i] = '0';
	                    break;
	                }
	            }
	            else{
	                if (c > 1){
	                    s[i] = '0';
	                    break;
	                }
	            }
	        }
	        cout << s << endl;
	        continue;
	    }
	    if (a && !b && c){
	        for (int i = 0; i < n; i++){
	            if ('0' <= s[i] && s[i] <= '9'){
	                if (a > 1){
	                    s[i] = 'a';
	                    break;
	                }
	            }
	            else{
	                if (c > 1){
	                    s[i] = 'a';
	                    break;
	                }
	            }
	        }
	        cout << s << endl;
	        continue;
	    }
	    if (a && b && !c){
	        for (int i = 0; i < n; i++){
	            if ('0' <= s[i] && s[i] <= '9'){
	                if (a > 1){
	                    s[i] = 'A';
	                    break;
	                }
	            }
	            else{
	                if (b > 1){
	                    s[i] = 'A';
	                    break;
	                }
	            }
	        }
	        cout << s << endl;
	        continue;
	    }
	    for (int i = 0; i < n; i++){
	        if (a && b && c) break;
	        if (!a){
	            a = 1;
	            s[i] = '0';
	            continue;
	        }
	        if (!b){
	            b = 1;
	            s[i] = 'a';
	            continue;
	        }
	        if (!c){
	            c = 1;
	            s[i] = 'A';
	            continue;
	        }
	    }
	    cout << s << endl;
	}
}

/*

*/