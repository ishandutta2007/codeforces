#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N = 205;
int n;
vector < int > ans1, ans2;
bool OK;
void go (vector < int > V1, vector < int > V2){
    for (int i = 0; i < V1.size(); i++)
        if (abs (V1[i]) > 1)
            return;
    if (V1.size() == n){
        OK = 1;
        ans1 = V1;
        ans2 = V2;
    }
    if (OK)
        return;
    V2.pb (0);
    V2.pb (0);
    for (int i = 0; i < V1.size(); i++)
        V2[i + 1] += V1[i];
    go (V2, V1);
    for (int i = 0; i < V1.size(); i++)
        V2[i + 1] -= 2 * V1[i];
    go (V2, V1);
}
int main() {
    n = 150;
    cin>>n;
    n++;
    vector < int > v1 = {1};
    vector < int > v2 = {};
    go (v1, v2);
    if (OK == 0){cout<<-1;return 0;}
    cout<<n - 1<<endl;
    if (ans1[n - 1] == -1)
        for (int i = 0; i < n; i++)
            ans1[i] = - ans1[i];
    if (ans2[n - 2] == -1)
        for (int i = 0; i < n - 1; i++)
            ans2[i] = - ans2[i];
    for (int i = 0; i < n; i++)
        cout<<ans1[i]<<" ";
    cout<<endl;
    cout<<n - 2<<endl;
    for (int i = 0; i < n - 1; i++)
        cout<<ans2[i]<<" ";
    cout<<endl;
    return 0;
}