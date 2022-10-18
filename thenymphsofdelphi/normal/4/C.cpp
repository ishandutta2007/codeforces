#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> name;
    string s;
    while (n--){
        cin >> s;
        if (name.count(s) == 0){
            cout << "OK" << endl;
            name[s] = 1;
        }
        else{
            cout << s << name[s] << endl;
            name[s] += 1;
        }
    }
}