#include <bits/stdc++.h>

using namespace std;

//#define TEST

int number[6] = {4, 8, 15, 16, 23, 42};

pair<int, int> possible(int n){
    for(int i = 0; i < 6; i++){
        if(n % number[i] == 0 && 
                (n / number[i] == 4 || 
                n / number[i] == 8 ||
                n / number[i] == 15 ||
                n / number[i] == 16 ||
                n / number[i] == 23 ||
                n / number[i] == 42)){
            return make_pair(number[i], n / number[i]);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << "? 1 2\n" << flush;
    int n12;
    cin >> n12;
    pair<int, int> oneAndTwo = possible(n12);

    cout << "? 2 3\n" << flush;
    int n23;
    cin >> n23;
    pair<int, int> twoAndThree = possible(n23);

    int two;
    if(twoAndThree.first == oneAndTwo.first || twoAndThree.first == oneAndTwo.second){
        two = twoAndThree.first;
    }
    else{
        two = twoAndThree.second;
    }

    int one = n12 / two;
    int three = n23 / two;

    cout << "? 4 4\n" << flush;
    int four;
    cin >> four;
    four = sqrt(four);

    cout << "? 5 5\n" << flush;
    int five;
    cin >> five;
    five = sqrt(five);

    vector<bool> temp(43, false);
    temp[one] = true;
    temp[two] = true;
    temp[three] = true;
    temp[four] = true;
    temp[five] = true;

    int six;
    for(int i = 0; i < 6; i++){
        if(!temp[number[i]]){
            six = number[i];
            break;
        }
    }

    cout << "! " << one << " " << two << " " << three << " " << four << " " << five << " " << six << "\n" << flush;
    
    return 0;
}