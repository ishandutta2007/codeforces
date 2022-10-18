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

int n, x, y;
int a[N], cnt[105];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(cnt, 0, sizeof(cnt));
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 1; i <= 100; i++){
	    if (cnt[i] == 1){
	        x++;
	    }
	    else if (cnt[i] >= 3){
	        y++;
	    }
	}
	if (y == 0){
	    if (x & 1){
	        cout << "NO";
	        return 0;
	    }
	    cout << "YES\n";
	    int u = 0;
	    for (int i = 0; i < n; i++){
	        if (cnt[a[i]] == 1){
	            cout << (char)(u + 'A');
	            u = 1 - u;
	        }
	        else{
	            cout << 'B';
	        }
	    }
	    return 0;
	}
	if ((x & 1) == 0){
        int t = 1, u = 0;
        cout << "YES\n";
        for (int i = 0; i < n; i++){
            if (cnt[a[i]] == 1){
                cout << (char)(u + 'A');
                u = 1 - u;
            }
            else{
                cout << 'A';
            }
        }
        return 0;
	}
	int t = 1, u = 0;
	cout << "YES\n";
	for (int i = 0; i < n; i++){
        if (cnt[a[i]] == 1){
            cout << (char)(u + 'A');
            u = 1 - u;
        }
        else if (cnt[a[i]] >= 3){
            if (x & 1){
                if (t){
                    t--;
                    cout << 'B';
                }
                else{
                    cout << 'A';
                }
            }
            else{
                cout << 'A';
            }
        }
        else{
            cout << 'A';
        }
	}
}

/*

*/