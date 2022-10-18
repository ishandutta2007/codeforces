#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

const int N = 1e5+1;

int s, b;
pair<int, int> a[N];
pair<int, int> c[N];
int ans[N];

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> s >> b;
    for(int i = 0; i < s; ++i){
        cin >> a[i].x;
        a[i].y = i;
    }
    for(int i = 0; i < b; ++i)
        cin >> c[i].x >> c[i].y;
    sort(a, a+s);
    sort(c, c+b);
    int j = 0,
        sum = 0;
    for(int i = 0; i < s; ++i){
        while(j < b && c[j].x <= a[i].x)
            sum += c[j++].y;
        ans[a[i].y] = sum;
    }
    for(int i = 0; i < s; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}