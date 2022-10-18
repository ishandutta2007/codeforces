#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string name[n], ip[n], command;
    for (int i = 0; i < n; i++){
        cin >> name[i] >> ip[i];
    }
    for (int i = 0; i < m; i++){
        cin >> command;
        cout << command << ' ';
        cin >> command;
        cout << command << " #";
        command.pop_back();
        for (int j = 0; j < n; j++){
            if (command == ip[j]){
                cout << name[j] << endl;
                break;
            }
        }
    }
}