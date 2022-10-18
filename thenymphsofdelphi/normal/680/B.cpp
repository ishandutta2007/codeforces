#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    m--;
    int a[n], num[n], dis[n], cnt = 0, t;
    memset(num, 0, sizeof(num));
    memset(dis, 0, sizeof(dis));
    for (int i = 0; i < n; i++){
        cin >> a[i];
        t = abs(m - i);
        dis[t]++;
        if (a[i]){
            num[t]++;
        }
    }
    for (int i = 0; i < n; i++){
        if (dis[i] == num[i] && num[i] != 0){
            cnt += num[i];
        }
    }
    cout << cnt;
}