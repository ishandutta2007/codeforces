#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    queue <int> qa, qb;
    map <pair<queue<int>, queue<int> >, int> state;
    int a, b, x;
    cin >> a;
    for (int i = 1; i <= a; i++){
        cin >> x;
        qa.push(x);
    }
    cin >> b;
    for (int i = 1; i <= b; i++){
        cin >> x;
        qb.push(x);
    }
    int f = 0, w;
    while (1){
        if (qa.empty()){
            cout << f << ' ' << 2;
            return 0;
        }
        if (qb.empty()){
            cout << f << ' ' << 1;
            return 0;
        }
        int &ok = state[make_pair(qa, qb)];
        if (ok){
            break;
        }
        ok = 1;
        f++;
        int A = qa.front();
        qa.pop();
        int B = qb.front();
        qb.pop();
        if (A > B){
            qa.push(B);
            qa.push(A);
        }
        else{
            qb.push(A);
            qb.push(B);
        }
    }
    cout << -1;
}