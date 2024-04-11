#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void INI_ERR(){
    cout << -1;
    exit(0);
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, x, y;
    cin >> n;
    int a[n][n], r[n], c[n];
    int d1 = 0, d2 = 0, sumr = -1, sumc = -1;
    int difr, difc, expctx, expcty, expctd;
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
            r[i] += a[i][j];
            c[j] += a[i][j];
            if (i == j) d1 += a[i][j];
            if (i + j == n - 1) d2 += a[i][j];
            if (a[i][j] == 0){
                x = i;
                y = j;
            }
        }
    }
    bool eqsum = true;
    if (n == 1){
    	cout << 1;
    	return 0;
    }
    for (int i = 0; i < n; i++){
        if (i != x){
            if (sumr == -1){
                sumr = r[i];
            }
            else if (sumr != r[i]){
            	//cout << "sumr" << endl;
				INI_ERR();
			}
        }
        if (i != y){
            if (sumc == -1){
                sumc = c[i];
            }
            else if (sumc != c[i]){
            	//cout << "sumc" << endl;
				INI_ERR();
			}
        }
    }
    if (!(sumr == sumc)){
    	//cout << "dif sumr sumc" << " " << sumr << " " << sumc << endl;
		INI_ERR();
	}
    expctx = sumr - r[x];
    expcty = sumc - c[y];
    if (expctx <= 0 || expcty <= 0 || expctx != expcty){
    	//cout << "expctx or expcty" << " " << expctx << " " << expcty << endl;
		INI_ERR();
	}
    if (x == y){
        expctd = sumr - d1;
        if (expctd <= 0 || expctd != expctx){
	    	//cout << "expctd1" << sumr << " " << d1 << " " << expctd << endl;
			INI_ERR();
		}
    }
    else{
    	if (sumr != d1){
    		//cout << "d1" << endl;
    		INI_ERR();
		}
	}
    if (x + y == n - 1){
        expctd = sumr - d2;
        if (expctd <= 0 || expctd != expctx){
	    	//cout << "expctd2" << sumr << " " << d2 << " " << expctd << endl;
			INI_ERR();
		}
    }
    else{
    	if (sumr != d2){
    		//cout << "d2" << endl;
    		INI_ERR();
		}
	}
    cout << expctx;
    return 0;
}