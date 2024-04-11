#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define int long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n, m;
vector < int > A[100005], B[100005];
main() {
    cin>>n>>m;
    if (n == 1 && m == 1){
        cout<<"YES\n";
        cout<<"1\n";return 0;
    }
    if (n == 1 && m == 4){
        cout<<"YES\n";
        cout<<"2 4 1 3\n";
        return 0;
    }
    if (n == 4 && m == 1){
        cout<<"YES\n";
        cout<<"2\n4\n1\n3\n";
        return 0;
    }
    if (n + m <= 5){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for (int i = 0; i < n + 5; i++){
        for (int j = 0; j < m + 5; j++){
            A[i].pb (0);
            B[i].pb (i * m + j + 1);
        }
    }
    if (m > 4){
        for (int i = 0; i < n; i++){
            int I = 0, p = i%2 * 2;
            for (int j = p; j < m + p; j += 2)
                A[i][I++] = B[i][j%m];
            for (int j = p + 1; j < m + p; j += 2)
                A[i][I++] = B[i][j%m];
        }
    }
    else if (n > 4){
        for (int i = 0; i < m; i++){
            int I = 0, p = i%2 * 2;
            for (int j = p; j < n + p; j += 2)
                A[I++][i] = B[j%n][i];
            for (int j = p + 1; j < n + p; j += 2)
                A[I++][i] = B[j%n][i];
        }
    }
    else {
        if (n == 3 && m == 3){
            cout<<"1 3 8\n5 9 4\n7 2 6\n";
            return 0;
        }
        if (n == 3 && m == 4){
            cout<<"1 3 5 2\n4 6 12 9\n11 8 10 7\n";
            return 0;
        }
        if (n == 4 && m == 3){
            cout<<"1 3 5\n6 8 10\n2 4 12\n9 11 7\n";
            return 0;
        }
        if (n == 2 && m == 4){
            cout<<"5 4 7 2\n3 6 1 8\n";
            return 0;
        }
        if (n == 4 && m == 2){
            cout<<"6 1\n3 8\n2 5\n7 4\n";
            return 0;
        }
        if (n == 4 && m == 4){
            cout<<"1 3 5 2\n4 6 8 9\n7 12 13 11\n15 10 16 14\n";
            return 0;
        }
        return 0;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}