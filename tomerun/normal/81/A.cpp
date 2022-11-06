#include <vector>
#include <list>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<char> stack;
    for(int i = 0; i < str.size(); ++i) {
        char cur = str[i];
        if(stack.empty() || stack.top() != cur) {
            stack.push(cur);
        }else{
            stack.pop();
        }
    }
    string result;
    while(!stack.empty()){
        result.push_back(stack.top());
        stack.pop();
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
}